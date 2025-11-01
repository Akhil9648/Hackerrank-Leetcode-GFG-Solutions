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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        while(st.find(head->val)!=st.end()) head=head->next;
        ListNode* ptr=head;
        while(ptr->next){
            if(st.find(ptr->next->val)!=st.end()){
                if(ptr->next->next){
                ptr->next=ptr->next->next;
                }
                else{
                    ptr->next=NULL;
                    break;
                }
            }
            else{
            ptr=ptr->next;
            }
        }
        return head;
    }
};