class Solution {
public:
    int GCD(int a,int b){
        if(b==0) return a;
        return GCD(b,a%b);
    }
    long long LCM(long a,long long b){
        return (a*b)/GCD(a,b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        vector<long long>ans;
        for(int i:nums){
        int curr=i;
            while(!ans.empty() && GCD(ans.back(),curr)>1){
                curr=LCM(ans.back(),curr);
                ans.pop_back();
            }
            ans.push_back(curr);
        }
        return vector<int>(ans.begin(),ans.end());
    }
};