class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        int n = nums.size();
        while(right<n){
            if(nums[right]==nums[right-1]){
                right ++;
            }
            else{
                nums[left+1] = nums[right];
                left++;
                right++;
            }
        }
        return left+1;
    }
};