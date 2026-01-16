class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(),hFences.end());
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(),vFences.end());
        int a=hFences.size();
        int b=vFences.size();
        unordered_set<int>ver,hor;
        for(int i=0;i<a;i++){
            for(int j=i+1;j<a;j++){
                hor.insert(hFences[j]-hFences[i]);
            }
        }
        for(int i=0;i<b;i++){
            for(int j=i+1;j<b;j++){
                ver.insert(vFences[j]-vFences[i]);
            }
        }
        int MOD=1e9+7;
        int side=-1;
        for(auto it:hor){
            if(ver.find(it)!=ver.end()){
                side=max(side,it);
            }
        }
        if(side==-1) return -1;
        long long ans=(1LL*side*side)%MOD;
        return (int)ans;
    }
};