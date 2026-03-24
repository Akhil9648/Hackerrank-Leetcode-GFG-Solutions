class Solution1 {
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
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                return {i+1,j+1};
            }
            if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1,-1};
    }
};