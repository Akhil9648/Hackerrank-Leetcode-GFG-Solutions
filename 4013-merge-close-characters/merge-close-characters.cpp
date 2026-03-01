class Solution {
public:
    string mergeCharacters(string s, int k) {
        int flag=0;
        while(!flag){
            flag=1;
            for(int i=0;i<s.size();i++){
                int j=i+1;
                while(j<min(i+k+1,(int)s.size())){
                    if(s[j]==s[i]){
                        s.erase(s.begin()+j);
                        flag=0;
                        j--;
                        break;
                    }
                    j++;
                    if(!flag) break;
                }
            }
        }
        return s;
    }
};