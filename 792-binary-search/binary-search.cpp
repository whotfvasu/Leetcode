class Solution {
public:

    bool check(int x, int y){
        return x==y;
    }
    

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0 , hi = n-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;

            if(check(nums[mid],target)){
                return mid;
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else lo= mid+1;
        }
        return -1;
    }
};