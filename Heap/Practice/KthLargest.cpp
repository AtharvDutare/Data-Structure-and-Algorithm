class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            pq.push(nums[i]);
        }
        while(pq.size()>k){
            pq.pop();
        }
        this->k=k;
    }
    
    int add(int val) {
        if(pq.empty()) {
            pq.push(val);
            return val;
        }
        else if(val<pq.top()) {
            if(pq.size()<k) {
                pq.push(val);
            }
            return pq.top();
        }
        else{
            if(pq.size()>=k){
                pq.pop();
            }
            pq.push(val);
            return pq.top();
        }
        return -1;
    }
};

/*
n is size of array;
q is no of query 
time complexity is O(n*log(n) + q*logk)
space complexity is O(k)
*/


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
