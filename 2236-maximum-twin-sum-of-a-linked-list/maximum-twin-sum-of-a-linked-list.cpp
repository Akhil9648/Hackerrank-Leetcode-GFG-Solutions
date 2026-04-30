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
        int n=arr.size();
        int i=0,j=n-1;
        int maxi=0;
        while(i<j){
            int sum=arr[i]+arr[j];
            maxi=max(maxi,sum);
            i++;
            j--;
        }
        return maxi;
    }
};
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
    ListNode *rev(ListNode *head){
        ListNode* curr=head,*prev=NULL;
        while(curr){
            ListNode *nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* findmid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* mid=findmid(head);
        ListNode *second=rev(mid);
        ListNode* curr=head;
        int maxi=0;
        while(second){
            int sum=curr->val+second->val;
            curr=curr->next;
            second=second->next;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};