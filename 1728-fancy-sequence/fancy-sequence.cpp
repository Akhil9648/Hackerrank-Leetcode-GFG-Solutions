class Fancy {
public:
 typedef long long ll;

    ll M = 1e9+7;

    vector<ll> seq;
    ll add = 0;
    ll mult = 1;

    //Binary Exponentiation for Fermat's Little Theorem -> power(mult, M-2);
    long long power(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = power(a, b/2);
        long long result = (half * half) % M;

        if(b%2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    Fancy() {
        
    }
    
    void append(int val) {
        long long x = ((val - add) % M + M) * power(mult, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        mult = (mult * m) % M;
        add  = (add * m) % M;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())
            return -1;

        return (seq[idx]*mult + add) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */