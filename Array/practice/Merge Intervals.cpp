#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // Step 1: Sort intervals based on the start value
        // intervals[i][0] is the start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            // Step 2: Check if 'merged' is empty or current interval doesn't overlap
            // merged.back()[1] is the end time of the last added interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Step 3: There is an overlap, so merge by updating the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int index = 0; // Pointer for the last merged interval

        for (int i = 1; i < intervals.size(); i++) {
            // Check for overlap: current start <= last merged end
            if (intervals[index][1] >= intervals[i][0]) {
                // Merge by updating the end time
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            } else {
                // No overlap: move index forward and copy the interval
                index++;
                intervals[index] = intervals[i];
            }
        }

        // Step 2: Resize the vector to remove the unused elements at the end
        intervals.resize(index + 1);
        
        return intervals;
    }
};

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // Step 2: Min-Heap to store end times (smallest end time at top)
        // std::greater<int> makes it a Min-Heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<vector<int>> result;

        int start = intervals[0][0];

        for (const auto& interval : intervals) {
            // If the smallest end time in heap is less than current start, they don't overlap
            if (!minHeap.empty() && minHeap.top() < interval[0]) {
                // This specific logic in your Java code assumes a shared start point
                // from the very first interval for the merged result.
                result.push_back({start, minHeap.top()});
                
                // Clear the heap to start a new merged range
                while(!minHeap.empty()) minHeap.pop();
                start = interval[0];
            }
            minHeap.push(interval[1]);
        }

        // Add the final merged interval
        if (!minHeap.empty()) {
            int maxEnd = 0;
            while (!minHeap.empty()) {
                maxEnd = max(maxEnd, minHeap.top());
                minHeap.pop();
            }
            result.push_back({start, maxEnd});
        }

        return result;
    }
};
class Solution {
    class DSU {
    private:
        unordered_map<int, int> parent;
        unordered_map<int, int> minStart;
        unordered_map<int, int> maxEnd;

    public:
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void add(int start, int end) {
            // FIX: If the start key already exists, update the maxEnd 
            // instead of overwriting the entire entry.
            if (parent.find(start) == parent.end()) {
                parent[start] = start;
                minStart[start] = start;
                maxEnd[start] = end;
            } else {
                maxEnd[start] = max(maxEnd[start], end);
            }
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                // Merge rootX into rootY
                parent[rootX] = rootY;
                minStart[rootY] = min(minStart[rootX], minStart[rootY]);
                maxEnd[rootY] = max(maxEnd[rootX], maxEnd[rootY]);
            }
        }

        vector<vector<int>> getMergedIntervals() {
            unordered_set<int> roots;
            vector<vector<int>> result;
            
            for (auto const& [key, val] : parent) {
                roots.insert(find(key));
            }

            for (int root : roots) {
                result.push_back({minStart[root], maxEnd[root]});
            }
            return result;
        }
    };

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // 1. Sort is crucial for the DSU to link consecutive overlaps
        sort(intervals.begin(), intervals.end());

        DSU dsu;
        // 2. Add all intervals, updating maxEnd for duplicate starts
        for (const auto& interval : intervals) {
            dsu.add(interval[0], interval[1]);
        }

        // 3. Union based on overlap logic
        // We use a runningMax to handle the case where a large interval 
        // covers several subsequent small intervals.
        int runningMax = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= runningMax) {
                dsu.unite(intervals[i-1][0], intervals[i][0]);
            }
            runningMax = max(runningMax, intervals[i][1]);
        }

        return dsu.getMergedIntervals();
    }
};