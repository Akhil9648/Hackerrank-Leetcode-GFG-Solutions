class Bank {
public:
    vector<long long> accounts;
    int n;
    Bank(vector<long long>& balance) {
        n=balance.size();
        accounts=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValid(account1) || !isValid(account2)) return false;
        if(accounts[account1-1]>=money){
            accounts[account1-1]-=money;
            accounts[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(!isValid(account)) return false;
            accounts[account-1]+=money;
            return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account)) return false;
        if(accounts[account-1]>=money){
            accounts[account-1]-=money;
            return true;
        }
        return false;
    }
     bool isValid(int account) {
        return account >= 1 && account <= n;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */