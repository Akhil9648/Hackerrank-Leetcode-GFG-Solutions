class Solution1 {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        unordered_map<int,int>mp;
        multiset<pair<int,int>> st; 
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            st.insert({it.second,it.first});
        }
        int i=k,j=0;
        vector<long long>ans;
        int u=x;
            long long sum=0;
            for(auto it=st.rbegin();it!=st.rend();it++){
                int a=it->first;
                int b=it->second;
                sum+=(1LL*a*b);
                u--;
                if(u==0) break;
            }
            ans.push_back(sum);
        while(i<n){
            if(nums[i]!=nums[j]){
            st.erase(st.find({mp[nums[j]], nums[j]}));
            mp[nums[j]]--;
            if(mp[nums[j]] > 0)
                st.insert({mp[nums[j]], nums[j]});
            if(mp[nums[i]] > 0)
                st.erase(st.find({mp[nums[i]], nums[i]}));
            mp[nums[i]]++;
            st.insert({mp[nums[i]], nums[i]});
            }
            int u=x;
            long long sum=0;
            for(auto it=st.rbegin();it!=st.rend();it++){
                int a=it->first;
                int b=it->second;
                sum+=(1LL*a*b);
                u--;
                if(u==0) break;
            }
            ans.push_back(sum);
            i++;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    long long sum=0;
    set<pair<int,int>>main,sec;
    void insert(const pair<int,int>&p,int x){
        if(main.size()<x || p>*main.begin()){
            sum+=1LL*p.first*p.second;
            main.insert(p);
            if(main.size()>x){
                auto smallest=*main.begin();
                sum-=1LL*smallest.first*smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        }else{
            sec.insert(p);
        }
    }
    void remove(const pair<int,int>& p,int x){
        if(main.find(p)!=main.end()){
            sum-=1LL*p.first*p.second;
            main.erase(p);
            if(!sec.empty()){
                auto largest=*sec.rbegin();
                sum+=1LL*largest.first*largest.second;
                main.insert(largest);
                sec.erase(largest);
            }
        }else{
            sec.erase(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int i=0,j=0;
        vector<long long>ans;
        unordered_map<int,int>mp;
        while(j<n){
                if(mp[nums[j]]>0){
                    remove({mp[nums[j]],nums[j]},x);
                }
                mp[nums[j]]++;
                insert({mp[nums[j]],nums[j]},x);
                if(j-i+1==k){
                    ans.push_back(sum);
                    remove({mp[nums[i]],nums[i]},x);
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    else{
                        insert({mp[nums[i]],nums[i]},x);
                    }
                    i++;
                }
                j++;
        }
        return ans;
    }
};