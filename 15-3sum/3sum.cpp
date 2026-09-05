class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int sum = -nums[i];

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int xsum = nums[left] + nums[right];

                if (xsum == sum) {
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    while (left < right &&
                           nums[left] == nums[left - 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right + 1])
                        right--;

                } else if (xsum > sum) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ans;
    }
};