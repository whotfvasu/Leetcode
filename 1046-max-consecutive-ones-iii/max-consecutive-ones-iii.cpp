class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zcnt = 0;
        int left = 0, ans = 0;

        for(int right=0;right<n;right++){
            if(nums[right]==0) zcnt++;

            while(zcnt>k){
                if(nums[left]==0) zcnt--;
                left++; 
            }

            ans = max(ans, right-left+1);
        }
        return ans;
    }
};