/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        priority_queue<pair<int,int>> pq;
        int maxDeadLine=-1;
        for(int i=0;i<n;i++) {
            maxDeadLine=max(maxDeadLine,arr[i].dead);
            pq.push({arr[i].profit,arr[i].dead});
            //cout<<arr[i].profit<<" "<<arr[i].dead<<endl;
        }
        vector<int> schedule(maxDeadLine+1,-1);
        int jobDone=0;
        int jobProfit=0;
        while(!pq.empty()) {
            int profit=pq.top().first;
            int dead=pq.top().second;
            //cout<<profit<<endl;
            pq.pop();
            for(int i=dead;i>0;i--) {
                if(schedule[i]==-1) {
                    schedule[i]=1;
                    jobDone++;
                    jobProfit+=profit;
                    break;
                }
            }
        }
        return {jobDone,jobProfit};
    } 
};