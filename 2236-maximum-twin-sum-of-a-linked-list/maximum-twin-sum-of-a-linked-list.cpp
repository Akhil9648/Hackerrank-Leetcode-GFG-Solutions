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
class Solution1 {
public:
    int pairSum(ListNode* head) {
       vector<int>arr;
       ListNode* temp=head;
       while(temp){
        arr.push_back(temp->val);
        temp=temp->next;
       }
       vector<int>rev=arr;
       reverse(rev.begin(),rev.end());
       int maxi=0;
       int n=rev.size();
       for(int i=0;i<n/2;i++){
            maxi=max(maxi,arr[i]+rev[i]);
       }
       return maxi;
    }
};
class Solution {
public:
    ListNode* findmid(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* rev(ListNode *head){
        if (!head || !head->next) return head;
        ListNode* ptr=head,*prev=NULL;
        while(ptr){
            ListNode* nxt=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* mid=findmid(head);
        ListNode* temp=mid->next;
        mid->next=NULL;
        temp=rev(temp);
        ListNode* ptr=head;
        int maxi=0;
        while(ptr && temp){
            maxi=max(ptr->val+temp->val,maxi);
            ptr=ptr->next;
            temp=temp->next;
        }
        return maxi;
    }
};