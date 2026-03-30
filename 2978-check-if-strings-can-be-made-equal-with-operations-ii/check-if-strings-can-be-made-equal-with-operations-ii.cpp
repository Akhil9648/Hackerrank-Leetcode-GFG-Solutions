class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        string o1,o2,e1,e2;
        for(int i=0;i<n;i++){
            if(i%2==0) e1.push_back(s1[i]);
            else o1.push_back(s1[i]);
        }
        for(int i=0;i<n;i++){
            if(i%2==0) e2.push_back(s2[i]);
            else o2.push_back(s2[i]);
        }
        sort(o1.begin(),o1.end());
        sort(e1.begin(),e1.end());
        sort(o2.begin(),o2.end());
        sort(e2.begin(),e2.end());
        if(o1==o2 && e1==e2) return true;
        return false;
    }
};