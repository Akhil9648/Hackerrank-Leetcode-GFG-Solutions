class Solution {
public:
    void NSL(vector<int> &arr,vector<int> &nsl)
    {
        stack<int> s;
        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty())
            {
            nsl.push_back(-1);
            }
            else
            nsl.push_back(s.top());
            s.push(i);
        }
    }
    void NSR(vector<int> &arr,vector<int> &nsr)
    {
        stack<int> s;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            s.pop();
            if(s.empty())
            nsr.push_back(arr.size());
            else
            nsr.push_back(s.top());
            s.push(i);
        }
        reverse(nsr.begin(),nsr.end());
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long count=0;
        int n=arr.size();
        long long mod=1e9+7;
        vector<int> nsl;
        vector<int> nsr;
        NSL(arr,nsl);
        NSR(arr,nsr);
        for(int i=0;i<arr.size();i++)
        {
            long long left=i-nsl[i];
            long long right=nsr[i]-i;
            count=(count+(1LL*arr[i]*left*right))%mod;
        }
        return (int)count;
    }
};