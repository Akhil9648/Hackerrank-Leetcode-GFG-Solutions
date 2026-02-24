
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']=i;
        }
        vector<int>ans;
        int maxi=0,st=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[s[i]-'a']);
            if(i==maxi){
                ans.push_back(maxi-st+1);
                st=maxi+1;
            }
        }
        return ans;
    }
};