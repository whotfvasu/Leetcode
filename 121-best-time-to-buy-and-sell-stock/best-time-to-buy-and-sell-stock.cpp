class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int maxProfit =0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxProfit = max(maxProfit, nums[i]-mini);
        }
        return maxProfit;
    }
};


