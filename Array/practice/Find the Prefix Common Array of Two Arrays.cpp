// approach: use set to store the elements of the array 
//and then find the common elements in the set
// and then iterate through the array and find the common elements
// and then return the count of the common elements
// time complexity: O(n^2) and space complexity: O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int> st1,st2;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            st1.insert(A[i]);
            st2.insert(B[i]);
            int t=0;
            for(auto &x:st1) {
                if(st2.find(x)!=st2.end()) {
                    t++;
                }
            }
            ans.push_back(t);
        }
        return ans;

    }
};
// optimized approach: use the frequency array to store the frequency of the elements of the array
// and then iterate through the array and find the common elements
// and then return the count of the common elements
// time complexity: O(n) and space complexity: O(1)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> freq(51,0);
        vector<int> ans;
        int t=0;
        for(int i=0;i<n;i++) {
            int t1=++freq[A[i]];
            int t2=++freq[B[i]];
            if(t1==2) {
                t++;
            }
            if(t2==2) {
                t++;
            }
            ans.push_back(t);
        }
        return ans;

    }
};