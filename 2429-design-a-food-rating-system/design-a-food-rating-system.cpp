class FoodRatings {
public:
    unordered_map<string,pair<string,int>>mp;
    unordered_map<string,set<pair<int,string>>>mp1;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            mp[foods[i]]={cuisines[i],ratings[i]};
            mp1[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine,old]=mp[food];
        mp1[cuisine].erase({-old,food});
        mp[food].second=newRating;
        mp1[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return mp1[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */