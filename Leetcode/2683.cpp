class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR=0;
        for(int &x:derived)
        {
            XOR^=x;
        }
        return XOR==0;
    }
};
