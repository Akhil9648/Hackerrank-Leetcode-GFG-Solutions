class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int col=n/rows;
        string s="";
        for(int i=0;i<col;i++){
            int j=i;
            while(j<n){
                s+=encodedText[j];
                j+=(col+1);
            }
        }
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        return s;
    }
};