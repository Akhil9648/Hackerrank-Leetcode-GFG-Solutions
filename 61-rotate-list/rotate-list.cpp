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
    ListNode* rotate(ListNode* head){
        ListNode* prev=NULL,* curr=head;
        while(curr->next){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        curr->next=head;
        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        if(!curr) return curr;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        if(count==1) return head;
        curr=head;
        k%=count;
        while(k--){
            curr=rotate(curr);
        }
        return curr;
    }
};