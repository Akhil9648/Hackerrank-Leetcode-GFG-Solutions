class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int n=g.size(),m=s.size();
        int count=0;
        int i=0,j=0;
        while(j<m && i<n){
            if(s[j]>=g[i]){
                i++;
                j++;
                count++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};