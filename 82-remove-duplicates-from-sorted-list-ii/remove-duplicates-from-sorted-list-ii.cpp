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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp=head,*pre=NULL;
        while(temp){
            int flag=0;
            while(temp->next && temp->val==temp->next->val){
                temp=temp->next;
                flag=1;
            }
            if(flag){
                if(!pre) head=temp->next;
                else pre->next=temp->next;
            }
            else pre=temp;
            temp=temp->next;
        }
        return head;
    }
};