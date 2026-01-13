class Solution {
public:
    bool isValid(string s){
        int m=s.size();
        if(m==0) return false;
        for(char c:s){
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || c=='_') continue;
            return false;
        }
        return true;
    }
    bool isValidBusiness(string s){
        if(s=="electronics" || s=="grocery" || s=="pharmacy" || s=="restaurant") return true;
        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<pair<string,string>>ans;
        for(int i=0;i<n;i++){
            if(isActive[i]==true && isValid(code[i]) && isValidBusiness(businessLine[i])){
                ans.push_back({businessLine[i],code[i]});
            }
        }
        sort(ans.begin(),ans.end());
        int m=ans.size();
        vector<string>result;
        for(int i=0;i<m;i++){
            result.push_back(ans[i].second);
        }
        return result;
    }
};