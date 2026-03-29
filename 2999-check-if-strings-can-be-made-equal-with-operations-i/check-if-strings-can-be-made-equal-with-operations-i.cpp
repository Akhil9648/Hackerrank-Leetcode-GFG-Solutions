class Solution {
public:
    bool solve(string &s1,string &s2,int i){
        if(s1==s2) return true;
        for(int u=i;u<4;u++){
            for(int v=u+2;v<4;v+=2){
                swap(s1[u],s1[v]);
                if(s1==s2) return true;
                if(solve(s1,s2,u+1)) return true;
                swap(s1[u],s1[v]);
                if(solve(s1,s2,u+1)) return true;
            }
        }
        return false;
    }
    bool canBeEqual(string s1, string s2) {
        return solve(s1,s2,0);
    }
};