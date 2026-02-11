class Solution {
public:
    int binarySearch(vector<int>& arr,int element,vector<bool>&mp){
        int i=0;
        int n=arr.size();
        int j=n-1;
        int mid=i+(j-i)/2;
        while(i<=j){
            if(arr[mid]==element){
                if(!mp[mid]){
                    return mid;
                }
                else{
                    int k=mid;
                    while((k-1)>=0&&arr[k-1]==element){
                        k--;
                    }
                    int l=mid;
                    while((l+1)<n&&arr[l+1]==element){
                        l++;
                    }
                    for(int t=k;t<=l;t++){
                        if(!mp[t]){
                            return t;
                        }
                    }
                    return -1;
                }
            }
            else if(arr[mid]>element){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
            mid=i+(j-i)/2;
        }
        return -1;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if((n%groupSize)!=0){
            return false;
        }
        vector<bool> mp(n,false);
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(!mp[i]){
                mp[i]=true;
                int tempGroupSize=groupSize;
                int count=1;
                //cout<<hand[i]<<" ";
                while(--tempGroupSize){
                    int index=binarySearch(hand,hand[i]+count,mp);
                    if(index==-1){
                        return false;
                    }
                    mp[index]=true;
                    count++;
                }
            }
        }
        return true;
    }
};