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