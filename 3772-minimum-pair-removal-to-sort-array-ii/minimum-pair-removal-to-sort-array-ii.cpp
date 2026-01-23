class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        vector<ll>arr(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>nexxt(n,0),prev(n,0);
        set<pair<ll,int>>st;
        int bp=0;
        for(int i=0;i<n;i++){
            nexxt[i]=i+1;
            prev[i]=i-1;
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) bp++;
            st.insert({(arr[i]+arr[i+1]),i});
        }
        int ops=0;
        while(bp>0){
            int first=st.begin()->second;
            int second=nexxt[first];
            int fl=prev[first];
            int sr=nexxt[second];
            ll a=st.begin()->first;
            st.erase(st.begin());
            if(arr[first] > arr[second]) {
                bp--;
            }
            if(fl>=0){
                if(arr[fl]>arr[first] && arr[fl]<=a) bp--;
                else if(arr[fl]<=arr[first] && arr[fl]>a) bp++;
            }
            if(sr<n){
                if((arr[sr]<arr[second]) && (arr[sr]>=a)) bp--;
                else if((arr[sr]>=arr[second]) && (arr[sr]<a)) bp++;
            }
            if(fl>=0){
                st.erase({arr[fl]+arr[first],fl});
                st.insert({arr[fl]+arr[first]+arr[second],fl});
            }
            if(sr<n){
                st.erase({arr[second]+arr[sr],second});
                st.insert({arr[first]+arr[second]+arr[sr],first});
                prev[sr]=first;
            }
            nexxt[first]=sr;
            arr[first]+=arr[second];
            ops++;
        }
        return ops;
    }
};