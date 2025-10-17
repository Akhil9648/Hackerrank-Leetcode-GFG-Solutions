class Solution {
public:
string s;
int k;
    unordered_map<long long,int>mp;
    int solve(int i,long long unique,bool canswap){
        if(i>=s.size()) return 0;
        long long key=((long long)i<<27)|(unique<<1)|canswap;
        if(mp.find(key)!=mp.end()) return mp[key];
        int chr=s[i]-'a';
        long long nunique=unique|(1LL<<chr);
        int ucount=__builtin_popcountll(nunique);
        int result=0;
        if(ucount>k){
            result=1+solve(i+1,1LL<<chr,canswap);
        }
        else{
            result=solve(i+1,nunique,canswap);
        }
        if(canswap){
            for(int j=0;j<26;j++){
                long long newc=unique|(1LL<<j);
                int ncount=__builtin_popcountll(newc);
                if(ncount>k){
                    result=max(result,1+solve(i+1,1LL<<j,false));
                }
                else{
                    result=max(result,solve(i+1,newc,false));
                }
            }
        }
        return mp[key]=result;
    }
    int maxPartitionsAfterOperations(string s_, int k_) {
      s=s_;
      k=k_;
      return solve(0,0,true)+1; 
    }
};