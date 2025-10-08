// There will be one more brute force by using two for loops and traversing over all the pairs and take the count of the valid pairs for that i and put them in the answer array Complexity-O(n^2)
// TLE TC-52
// Time Complexity-O(m log m + n·m)
class Solution1 {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=potions.size();
        int n=spells.size();
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            int j=0,flag=0;
            while(j<m){
                if(1LL*(1LL*spells[i]*1LL*potions[j])>=1LL*success){
                    flag=1; 
                    break;
                }
                j++;
            }
            if(flag){
                ans.push_back(m-j);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
// Optimization Binary Search On Answers
// Time complexity-O(n*m*logm)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=potions.size();
        int n=spells.size();
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            int l=0,h=m-1,mini=m;
            while(l<=h){
                int mid=(l+h)/2;
                if((1LL*spells[i]*potions[mid])>=success){
                    h=mid-1;
                    mini=min(mini,h);
                }
                else{
                    l=mid+1;
                }
            }
            ans.push_back((m-mini-1>0)?m-mini-1:0);
        }
        return ans;
    }
};