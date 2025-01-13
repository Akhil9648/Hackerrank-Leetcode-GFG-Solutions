class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        int sum=0;
        for(int i=0;i<26;i++)
        {
            if((freq[i]%2)!=0)
            {
                freq[i]=1;
            }
            else if(freq[i]>2)
            {
                freq[i]=2;
            }
                sum+=freq[i];
        }
        return sum;
    }
};
