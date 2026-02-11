/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int x=0;
        int y=0;
        m--;
        n--;
        while(head) {
            for(int k=y;k<=n&&head;k++) {
                ans[x][k]=head->val;
                head=head->next;
            }
            x++;
            for(int k=x;k<=m&&head;k++) {
                ans[k][n]=head->val;
                head=head->next;
            }
            n--;
            if(y<=n) {
                for(int k=n;k>=y&&head;k--) {
                    ans[m][k]=head->val;
                    head=head->next;
                }
                m--;
            }
            if(x<=m) {
                for(int k=m;k>=x&&head;k--) {
                    ans[k][y]=head->val;
                    head=head->next;
                }
                y++;
            }
        }
        return ans;
    }
};