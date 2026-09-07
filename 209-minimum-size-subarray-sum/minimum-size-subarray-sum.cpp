class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left =0, right = 0;
        int sum = nums[left];

        while(right<n){
            if(sum>=target){
                ans = min(ans, right-left+1);
                sum -= nums[left];
                left++;
            }
            else{
                right++;
                if(right==n) break;
                sum+=nums[right];
            }
        }

        if(ans==INT_MAX) return 0;

        return ans;
    }
};


// if(sum>t)
//    ans = min()
//    sum-=arr[l]
//    l++;
// else
//    r++; 
//     sum+=arr[r] 
   