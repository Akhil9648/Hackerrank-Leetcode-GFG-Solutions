class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>arr(26,vector<int>(26,1e9));
        int n=changed.size();
        for(int i=0;i<n;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            arr[u][v]=min(arr[u][v],cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(arr[i][k]!=1e9 && arr[k][j]!=1e9){
                        arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
                    }
                }
            }
        }    
        n=source.size();
        long long res=0;
        for(int i=0;i<n;i++){
            if(source[i]==target[i]) continue;
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(arr[u][v]==1e9) return -1;
            res+=arr[u][v];
        }
        return res;
    }
};