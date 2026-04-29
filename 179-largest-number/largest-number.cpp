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
        if (arr[0] == "0") return "0";
        for(auto it:arr){
            ans+=it;
        }
        return ans;
    }
};