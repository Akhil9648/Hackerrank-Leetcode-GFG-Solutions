#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        budget--;
        // Store items as pairs {cost, capacity} to keep them linked during sorting
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {costs[i], capacity[i]};
        }
        
        // 1. Sort items by Cost (O(N log N))
        // This allows us to use Binary Search later
        sort(items.begin(), items.end());
        
        // 2. Separate them back into vectors for easier access (optional but cleaner)
        // and build the Prefix Max Array.
        // prefixMax[i] stores the maximum capacity found in items[0...i]
        vector<int> sortedCosts(n);
        vector<int> prefixMax(n);
        
        for (int i = 0; i < n; ++i) {
            sortedCosts[i] = items[i].first;
            
            if (i == 0) {
                prefixMax[i] = items[i].second;
            } else {
                prefixMax[i] = max(prefixMax[i-1], items[i].second);
            }
        }
        
        long long maxCap = 0;
        
        // 3. Iterate through every item and find its best partner (O(N log N))
        for (int i = 0; i < n; ++i) {
            int currentCost = items[i].first;
            int currentCap = items[i].second;
            
            // Optimization: If the single item is already over budget, stop.
            // (Since array is sorted, all future items will also be over budget)
            if (currentCost > budget) break; 
            
            // Option A: Take only this single item
            maxCap = max(maxCap, (long long)currentCap);
            
            // Option B: Take this item + one previous item
            int remainingBudget = budget - currentCost;
            
            // We need to find an index 'j' < 'i' such that sortedCosts[j] <= remainingBudget.
            // We use upper_bound to find the first element GREATER than remainingBudget,
            // then step back one position to get the element <= remainingBudget.
            
            // Search only in the range [0, i) because we don't want to pair the item with itself
            // or count pairs twice.
            auto it = upper_bound(sortedCosts.begin(), sortedCosts.begin() + i, remainingBudget);
            
            // 'it' points to the first item that is too expensive.
            // The index of the item just before it is validIdx.
            int validIdx = distance(sortedCosts.begin(), it) - 1;
            
            // If validIdx is >= 0, it means we found at least one valid partner.
            // Because of our PrefixMax array, prefixMax[validIdx] is guaranteed to be
            // the largest capacity among all affordable partners.
            if (validIdx >= 0) {
                maxCap = max(maxCap, (long long)currentCap + prefixMax[validIdx]);
            }
        }
        
        return (int)maxCap;
    }
};