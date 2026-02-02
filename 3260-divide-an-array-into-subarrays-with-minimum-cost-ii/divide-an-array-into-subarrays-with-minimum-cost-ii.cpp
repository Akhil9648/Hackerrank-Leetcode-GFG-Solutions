class Solution1 {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        vector<int>window;
        int n=nums.size();
        long long ans=nums[0];
        for(int i=1;i<=dist;i++){
            window.push_back(nums[i]);
        }
        long long mini=LLONG_MAX;
        for(int i=1;i+dist<n;i++){
            long long sum=0;
            window.push_back(nums[i+dist]);
            if(k-1>window.size()) break;
            vector<int>arr=window;
            sort(arr.begin(),arr.end());
            for(int u=0;u<k-1;u++){
                sum+=arr[u];
            }
            mini=min(mini,sum);
            window.erase(window.begin(),window.begin()+1);
        }
        ans+=mini;
        return ans;
    }
};
class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;

    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P> kMinimum; 
        set<P> remaining;

        ll sum = 0;

        int i = 1;
        while(i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];
            if(kMinimum.size() > k-1) {
                P temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            i++;
        }

        ll result = LONG_MAX;
        while(i < n) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if(kMinimum.size() > k-1) {
                P temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }

            result = min(result, sum);

            P remove = {nums[i-dist], i-dist};
            if(kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;

                if(!remaining.empty()) {
                    P temp = *remaining.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {
                remaining.erase(remove);
            }

            i++;
        }

        return nums[0] + result;
    }
};