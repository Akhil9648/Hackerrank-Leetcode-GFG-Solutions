class Solution1 {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]) ans=min(ans,(abs(i-j)+abs(j-k)+abs(i-k)));
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it:mp){
            int m=it.second.size();
            if(m>=3){
                int a=it.second[0],b=it.second[1],c=it.second[2];
                for(int i=0;i+2<m;i++){
                    a=it.second[i];
                    b=it.second[i+1];
                    c=it.second[i+2];
                    ans=min(ans,(abs(a-b)+abs(b-c)+abs(c-a)));
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};