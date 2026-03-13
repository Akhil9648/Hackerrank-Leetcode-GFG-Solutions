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
    ListNode* findmid(ListNode *head){
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *head1,ListNode* head2){
        ListNode* ans=new ListNode(-1);
        ListNode *ptr=ans;
        while(head1 && head2){
            if(head1->val<head2->val){
                ptr->next=head1;
                // ptr=head1;
                head1=head1->next;
            }
            else{
                ptr->next=head2;
                // ptr=head2;
                head2=head2->next;
            }
            ptr = ptr->next;
        }
        while(head1){
            ptr->next=head1;
            ptr=head1;
            head1=head1->next;
        }
        while(head2){
            ptr->next=head2;
            ptr=head2;
            head2=head2->next;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *mid=findmid(head);
        ListNode* left=head,*right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};