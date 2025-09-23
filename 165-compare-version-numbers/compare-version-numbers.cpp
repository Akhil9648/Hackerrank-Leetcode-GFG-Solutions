class Solution {
public:
    int compareVersion(string version1, string version2) {
        string s1="0",s2="0";
        int flag=0;
        int i=0,j=0;
        while(i<version1.size()){
            if(version1[i]!='.'){
                s1+=version1[i];
                i++;
            }
            else break;
        }
        while(j<version2.size()){
            if(version2[j]!='.'){
                s2+=version2[j];
                j++;
            }
            else break;
        }
        if(stoi(s1)<stoi(s2)){
                return -1;
            }
        if(stoi(s1)>stoi(s2)){
                return 1;
        }
        while(i<version1.size() || j<version2.size()){
            s1="0",s2="0";
            while(version1[i]!='.' && i<version1.size()){
                s1+=version1[i];
                i++;
            }
            if(version1[i]=='.') i++;
            while(version2[j]!='.' && j<version2.size()){
                s2+=version2[j];
                j++;
            }
            if(version2[j]=='.') j++;
            if(stoi(s1)<stoi(s2)){
                return -1;
            }
            if(stoi(s1)>stoi(s2)){
                return 1;
            }
        }
        // while(s1.size()<s2.size()){
        //     s1+='0';
        // }
        // while(s2.size()<s1.size()){
        //     s2+='0';
        // }
        return 0;
    }
};