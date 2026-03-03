class Solution1 {
public:
    string generate(int n) {
        if (n == 1) return "0";
        string prev = generate(n - 1);
        string curr = prev;
        for (int i = 0; i < curr.length(); i++) {
            curr[i] = (curr[i] == '0') ? '1' : '0';
        }
        reverse(curr.begin(), curr.end());
        
        return prev + "1" + curr;
    }

    char findKthBit(int n, int k) {
        string finalString = generate(n);
        return finalString[k - 1];
    }
};
class Solution {
public:
    char findKthBit(int n, int k) {
        int total=(1<<n)-1;
        if(n==1) return '0';
        if(k<ceil(total/2.0)) return findKthBit(n-1,k);
        else if(k==ceil(total/2.0)) return '1';
        char c=findKthBit(n,total-k+1);
        return c=='0'?'1':'0';
    }
};