/*
struct Item{
    int value;
    int weight;
};
*/

/* 
    time complexity is  O(N*log(N))
    space complexity is O(N)
*/


class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        priority_queue<pair<double,int>> pq;

        for(int i=0;i<n;i++) {
            int val=arr[i].value;
            int w=arr[i].weight;
            pq.push({1.0*val/w,w});
        }
        double value=0;
        while(w>0&&!pq.empty()) {
            double ratio=pq.top().first;
            int weight=pq.top().second;
            pq.pop();
            if(w>=weight) {
                value+=(ratio*weight);
                w-=weight;
            }
            else {
                value+=(ratio*w);
                w=0;
            }
        }
        return value;
    }
};