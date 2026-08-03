class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]> nums[i]){
                ind = i;
                break;
            }
        }
        if (ind == -1){
            return reverse(nums.begin(), nums.end());
        }
        // ind + 1 -> n-1 ===> just greater then no. at ind 
        int x = 0;
        for(int i=n-1;i>=ind+1;i--){
            if(nums[i]>nums[ind]){
                x = i;
                break;
            }
        }

        swap(nums[x], nums[ind]);

        reverse(nums.begin()+ind + 1, nums.end());
    }
};