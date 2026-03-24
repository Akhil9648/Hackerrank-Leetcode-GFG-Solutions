class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        int n=numbers.size();
        for(int i=0;i<n;i++){
            mp[numbers[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(mp.count(target-numbers[i])){
                int a=mp[target-numbers[i]];
                return {i+1,a+1};
            }
        }
        return {-1,-1};
    }
};