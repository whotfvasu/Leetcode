class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        if (n==0) return 0;

        
        int maxi = 1;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1) == st.end()){
                int x = nums[i];
                int cnt = 1;
                while(st.find(x+1) != st.end()){
                    x++;
                    cnt++;
                    st.erase(x);   
                }
                maxi = max(maxi,cnt);
            }
        }

        return maxi;

    }
};