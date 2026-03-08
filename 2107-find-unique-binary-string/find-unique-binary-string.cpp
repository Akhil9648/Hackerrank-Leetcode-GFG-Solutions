class Solution {
public:
    int to_int(string s){
        int k=0,ans=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            // int a=
            ans+=pow(2,k)*(s[i]-'0');
            k++;
        }
        return ans;
    }
    string to_bin(int n,int u){
        string ans="";
        while(n){
            int d=n%2;
            ans+=(d+'0');
            n/=2;
        }
        while(ans.size()<u) ans+='0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>st;
        int n=nums[0].size();
        for(auto it:nums){
            int a=to_int(it);
            st.insert(a);
        }
        for(int i=0;i<=pow(2,n);i++){
            if(!st.count(i)){
                return to_bin(i,n);
            }
        }
        return "";
    }
};