class Solution {
public:
    string rotate(string s,int b){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        queue<string>q;
        q.push(s);
        unordered_set<string>vis;
        vis.insert(s);
        string small=s;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(curr<small){
                small=curr;
            }
            string temp=curr;
            for(int i=1;i<curr.size();i+=2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';
            }
            if(vis.find(temp)==vis.end()){
                q.push(temp);
                vis.insert(temp);
            }
            temp=rotate(curr,b);
            if(vis.find(temp)==vis.end()){
                q.push(temp);
                vis.insert(temp);
            }
        }
        return small;
    }
};