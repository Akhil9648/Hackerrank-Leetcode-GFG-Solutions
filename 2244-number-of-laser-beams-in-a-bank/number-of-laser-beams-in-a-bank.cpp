class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0;
        int a=0;
        for(char c:bank[0]){
                if(c=='1') a++;
        }
        for(int i=0;i<n-1;i++){
            int b=0;
            for(char c:bank[i+1]){
                if(c=='1') b++;
            }
            ans+=(a*b);
            if(b>0) a=b;
        }
        return ans;
    }
};