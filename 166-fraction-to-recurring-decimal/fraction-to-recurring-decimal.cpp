class Solution {
public:
    string fractionToDecimal(int num, int dnum) {
        if(num==0) return "0";
        string ans="";
        if((long long)num * (long long)dnum<0) ans+="-";
        long long anum=labs(num),adnum=labs(dnum);
        long long a=anum/adnum;
        ans+=to_string(a);
        long long rem=anum%adnum;
        if(rem==0) return ans;
        ans+=".";
        unordered_map<int,int>mp;
        while(rem!=0){
            if(mp.count(rem)){
                ans.insert(mp[rem],"(");
                ans+=")";
                break;
            }
            mp[rem]=ans.length();
            rem*=10;
            int d=rem/adnum;
            ans+=to_string(d);
            rem=rem%adnum;
        }
        return ans;
    }   
};