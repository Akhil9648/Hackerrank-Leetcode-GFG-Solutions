class Solution1 {
public:
    int n,LIM;
    int solve(int i,string& s,int cnt0,int cnt1,vector<vector<vector<int>>>& dp){
        if(i>=n) return 0;
        if (cnt0 >= LIM) return 0;
        if(dp[i][cnt0][cnt1]!=-1) return dp[i][cnt0][cnt1];
        int ans=0;
        int a=cnt0+(s[i]=='0'?1:0);
        int b=cnt1+(s[i]=='1'?1:0);
        if(b>=a*a){
            ans++;
        }
        ans+=solve(i+1,s,a,b,dp);
        if(cnt0==0 && cnt1==0) ans+=solve(i+1,s,0,0,dp);
        return dp[i][cnt0][cnt1]=ans;
    }
    int numberOfSubstrings(string s) {
        n=s.size();
        LIM = sqrt(n) + 2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(LIM,vector<int>(n+1,-1)));
        return solve(0,s,0,0,dp);   
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>cumsum(n,0);
        cumsum[0]=((s[0]=='1')?1:0);
        for(int i=1;i<n;i++){
            cumsum[i]=cumsum[i-1]+((s[i]=='1')?1:0);
        }   
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int one=cumsum[j]-((i-1>=0)?cumsum[i-1]:0);
                int zero=(j-i+1)-one;
                if(zero*zero>one){
                    int skip=(zero*zero)-one;
                    j+=skip-1;
                }
                else if(zero*zero==one){
                    result+=1;
                }
                else{
                    result+=1;
                    int k=sqrt(one)-zero;
                    int nxt=j+k;
                    if(nxt>=n){
                        result+=(n-j-1);
                        break;
                    }
                    else{
                        result+=k;
                    }
                    j=nxt;
                }
            }
        }
        return result;
    }
};