class Solution {
public:
    string conv(int n){
        if(n==0) return "0";
        string curr="";
        while(n){
            int a=n%2;
            curr+=(a+'0');
            n/=2;
        }
        reverse(curr.begin(), curr.end());
        return curr;
    }
    int minFlips(int a, int b, int c) {
        string ac=conv(a);
        string bc=conv(b);
        string cc=conv(c);
        string o="";
        while(ac.size()<bc.size()){
            ac.insert(0,1,'0');
        }
        while(ac.size()>bc.size()){
            bc.insert(0,1,'0');
        }
        while(ac.size()>cc.size()){
            cc.insert(0,1,'0');
        }
        while(ac.size()<cc.size()){
            ac.insert(0,1,'0');
            bc.insert(0,1,'0');
        }
        int count=0;
        for(int i=0;i<ac.size();i++){
            if(cc[i]=='1'){
                if(ac[i]=='1' || bc[i]=='1') continue;
                count++;
            }
            if(cc[i]=='0'){
                if(ac[i]=='1') count++;
                if(bc[i]=='1') count++;
            }
        }
        return count;
    }
};