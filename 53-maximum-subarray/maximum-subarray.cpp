class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestend = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = bestend + nums[i];
            int v2 = nums[i];
            bestend = max(v1,v2);
            res = max(res, bestend);
        }
        return res;
    }
};

