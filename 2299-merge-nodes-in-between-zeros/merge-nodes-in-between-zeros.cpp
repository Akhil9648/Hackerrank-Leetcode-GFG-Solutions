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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* ptr=ans;
        ListNode *curr=head;
        int sum=0;
        while(curr){
            if(curr->val==0 && sum>0){
                ptr->next=new ListNode(sum);
                sum=0;
                ptr=ptr->next;
            }
            sum+=curr->val;
            curr=curr->next;
        }
        return ans->next;
    }
};