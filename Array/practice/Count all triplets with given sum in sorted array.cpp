//approach 1 O(n^3) time complexity
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(arr[i]+arr[j]+arr[k]==target) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
//approach 2 O(n^2) time complexity
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int j=i+1;
            int k=n-1;
            int newTar=target-arr[i];
            while(j<k) {
                if(arr[j]+arr[k]<newTar) {
                    j++;
                }
                else if(arr[j]+arr[k]>newTar) {
                    k--;
                }
                else {
                    int t1=1;
                    int t2=1;
                    if(arr[j]==arr[k]) {
                        int w=k-j+1;
                        ans+=(w*(w-1))/2;
                        break;
                    }
                    while(j+1<n&&arr[j]==arr[j+1]) {
                        j++;
                        t1++;
                    }
                    while(k-1>i&&arr[k-1]==arr[k]) {
                        k--;
                        t2++;
                    }
                    ans+=t1*t2;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};