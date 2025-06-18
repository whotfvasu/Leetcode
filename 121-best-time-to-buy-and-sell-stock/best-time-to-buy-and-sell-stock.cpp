class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxdiff=0;
        int n = prices.size();
        for(int i =0;i<n;i++){
            mini = min(mini,prices[i]);
            int diff = prices[i]-mini;
            maxdiff = max(maxdiff,diff);
        }
        return maxdiff;
    }
};