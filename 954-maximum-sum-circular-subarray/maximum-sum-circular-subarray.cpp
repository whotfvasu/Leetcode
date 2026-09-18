class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];

        int bestend = nums[0];
        int worstend = nums[0];

        int maxres = nums[0];
        int minres = nums[0];

        for (int i = 1; i < n; i++) {
            sum += nums[i];

            bestend = max(bestend + nums[i], nums[i]);
            worstend = min(worstend + nums[i], nums[i]);

            maxres = max(maxres, bestend);
            minres = min(minres, worstend);
        }

        // All elements are negative
        if (maxres < 0)
            return maxres;

        return max(maxres, sum - minres);
    }
};