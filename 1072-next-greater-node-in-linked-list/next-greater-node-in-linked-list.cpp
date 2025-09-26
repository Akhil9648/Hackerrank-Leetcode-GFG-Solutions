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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n && arr[i]>=arr[j]){
                j++;
            }
            if(j==n) ans.push_back(0);
            else ans.push_back(arr[j]);
        }
        return ans;
    }
};