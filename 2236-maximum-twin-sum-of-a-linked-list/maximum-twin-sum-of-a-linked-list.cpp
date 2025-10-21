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