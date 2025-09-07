class Solution1 {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>ans(n,0);
        ans[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) ans[i]=ans[i-1]+1;
            else ans[i]=1;
        }
        int sum=ans[n-1];
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) ans[i]=max(ans[i],ans[i+1]+1);
            sum+=ans[i];
        }
        return sum;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1,sum=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peek=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peek++;
                sum+=peek;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peek){
                sum+=(down-peek);
            }
        }
        return sum;
    }
};