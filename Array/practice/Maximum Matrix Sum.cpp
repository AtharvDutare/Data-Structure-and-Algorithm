class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int n=matrix.size();
        int negCount=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]<0)
                    negCount++;
                pq.push(abs(matrix[i][j]));
            }
        }
        while(pq.size()>negCount) {
            int t1=pq.top();
            pq.pop();
            ans+=t1;
        }
        while(pq.size()>=2) {
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            negCount-=2;
            ans+=(t1+t2);
        }
        if(pq.size()==1&&negCount==1) {
            ans-=pq.top();
            pq.pop();
        }
        return ans;
    }
};
//java
import java.util.Comparator;
class Solution {
    
    public long maxMatrixSum(int[][] matrix) {
        long ans=0;
        int n=matrix.length;
        PriorityQueue<Integer> pq=new PriorityQueue<>(new Abc());
        int negCount=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]<0) {
                    negCount++;
                }
                pq.add(Math.abs(matrix[i][j]));
            }
        }
        while(pq.size()>negCount) {
            int t1=pq.peek();
            pq.poll();
            ans+=t1;
        }
        while(pq.size()>=2) {
            int t1=pq.peek();
            pq.poll();
            int t2=pq.peek();
            pq.poll();
            negCount-=2;
            ans+=(t1+t2);
        }
        if(pq.size()==1&&negCount==1) {
            ans-=pq.poll();
        }
        return ans;
    }
    class Abc implements Comparator<Integer>{
        public int compare(Integer a,Integer b) {
            return a<b?1:-1;
        }
    }
}

import java.util.Comparator;
class Solution {
    
    public long maxMatrixSum(int[][] matrix) {
        long ans=0;
        int n=matrix.length;
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)->b-a);
        int negCount=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]<0) {
                    negCount++;
                }
                pq.add(Math.abs(matrix[i][j]));
            }
        }
        while(pq.size()>negCount) {
            int t1=pq.peek();
            pq.poll();
            ans+=t1;
        }
        while(pq.size()>=2) {
            int t1=pq.peek();
            pq.poll();
            int t2=pq.peek();
            pq.poll();
            negCount-=2;
            ans+=(t1+t2);
        }
        if(pq.size()==1&&negCount==1) {
            ans-=pq.poll();
        }
        return ans;
    }
}