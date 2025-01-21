class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=mat[i][j];
                mp[val]={i,j};
            }
        }
        vector<int> rowi(n,0);
        vector<int>coli(m,0);
        for(int i=0;i<arr.size();i++)
        {
            int val=arr[i];
            auto [row,col]=mp[val];
            rowi[row]++;
            coli[col]++;
            if(rowi[row]==m || coli[col]==n)
            {
                return i;
            }
        }
        return -1;
    }
};
