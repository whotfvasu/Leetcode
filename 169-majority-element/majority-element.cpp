class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int cnt = 0;

        for(int i=0;i<n;i++){ 
            if(maxi==nums[i]){
                cnt++;
            }
            else{
                if(cnt==1){
                    maxi = nums[i];
                }
                else cnt--;
            }
        }
        return maxi;

        
    }
};