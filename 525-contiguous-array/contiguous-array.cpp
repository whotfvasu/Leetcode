class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        int res = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++; if(nums[i]==1) one++;
            int diff = one-zero;
            if(diff==0){
                res = max(res,i+1);
                continue;
            }
            else{
                if(mpp.find(diff)==mpp.end()){
                    mpp[diff] = i;
                }
                else{
                    int len = i-mpp[diff];
                    res = max(res,len);

                }
            }
        }
        return res;
    }
};