class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(),arr.end(),[](string &a,string &b){
            return a+b>b+a;
        });
        string ans="";
        for(auto it:arr){
            if(ans!="0") ans+=it;
        }
        return ans;
    }
};