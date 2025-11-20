// Approach-1 TLE
class Solution1 {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        unordered_set<int>st;
        sort(intervals.begin(),intervals.end(),[](auto & a,auto & b){
            return a[1]<b[1];
        });
        for(auto it:intervals){
            int low=it[0];
            int high=it[1];
            int flag=2;
            for(int i=low;i<=high;i++){
                if(flag==0) break;
                if(st.find(i)!=st.end()) flag--;
            }
            if(flag==0) continue;
            for(int j=high;j>=low && flag>0;j--){
                if(st.find(j)!=st.end()) continue;
                st.insert(j);
                cout<<j<<" ";
                flag--;
            }
        }
        return st.size();
    }
};
// Approach-2
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto & a,auto & b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1]<b[1];
        });
        int res=0;
        int a=-1,b=-1;
        for(auto it:intervals){
            int low=it[0],high=it[1];
            bool ain=(a>=low && a<=high);
            bool bin=(b>=low && b<=high);
            if(ain && bin) continue;
            else if(bin){
                res+=1;
                a=b;
                b=high;
            }
            else{
                res+=2;
                a=high-1;
                b=high;
                if (a < low) a = low;
            }
        }
        return res;
    }
};
