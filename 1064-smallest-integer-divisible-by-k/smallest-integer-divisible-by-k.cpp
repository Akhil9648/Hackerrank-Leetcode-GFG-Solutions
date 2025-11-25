class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0) return -1;
        unordered_set<int>st;
        int n=1,count=1;
        while(n!=0){
            int a=n%k;
            if(st.count(a)) return -1;
            st.insert(a);
            if(a==0) return count;
            count++;
            n=a*10+1;
        }
        return count;
    }
};