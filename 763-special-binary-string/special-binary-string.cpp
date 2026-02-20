class Solution {
public:
    string solve(string s){
        int n=s.size();
        int sum=0,start=0;
        vector<string>specials;
        for(int i=0;i<n;i++){
            sum+=s[i]=='1'?1:-1;
            if(sum==0){
                string inner=s.substr(start+1,i-start-1);
                specials.push_back("1"+solve(inner)+"0");
                start=i+1;
            }
        }
        sort(specials.begin(),specials.end(),greater<string>());
        string res="";
        for(auto c:specials) res+=c;
        return res;
    }
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};