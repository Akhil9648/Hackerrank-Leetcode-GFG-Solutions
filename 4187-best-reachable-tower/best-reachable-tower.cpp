class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n=towers.size();
        vector<pair<int,pair<int,int>>>arr;
        for(auto it:towers){
            arr.push_back({it[2],{it[0],it[1]}});
        }
        vector<vector<int>>ans;
        int maxi=0;
        sort(arr.begin(),arr.end());
        for(auto it:arr){
            int dis=abs(it.second.first-center[0])+abs(it.second.second-center[1]);
            if(dis<=radius){
                if(it.first>maxi){
                    ans.erase(ans.begin(),ans.end());
                    ans.push_back({it.second.first,it.second.second});
                    maxi=it.first;
                }
                else if(it.first==maxi){
                    ans.push_back({it.second.first,it.second.second});
                }
            }
        }
        if(ans.size()>0) return ans[0];
        return {-1,-1};
    }
};