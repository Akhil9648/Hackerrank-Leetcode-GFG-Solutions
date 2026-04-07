class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(auto it:obstacles){
            st.insert(to_string(it[0])+'_'+to_string(it[1]));
        }
        int n=commands.size();
        int maxi=0;
        int x=0,y=0;
        pair<int,int>p={0,1};
        for(int i=0;i<n;i++){
            if(commands[i]==-2){
                p={-p.second,p.first};
            }
            else if(commands[i]==-1){
                p={p.second,-p.first};
            }
            else{
                for(int step=0;step<commands[i];step++){
                    int newX=x+p.first;
                    int newY=y+p.second;
                    string key=to_string(newX)+'_'+to_string(newY);
                    if(st.count(key)) break;
                    x=newX;
                    y=newY;
                }
            }
            maxi=max(maxi,x*x+y*y);
        }
        return maxi;
    }
};