class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v (n,0);
        int negind = 1 ; int posind = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                v[negind]=nums[i];
                negind+=2;
            }
            else{
                v[posind]=nums[i];
                posind+=2;
            }
        }
        return v;
    }
};