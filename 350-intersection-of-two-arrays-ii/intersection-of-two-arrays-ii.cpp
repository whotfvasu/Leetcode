class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0;

        while (i < nums1.size()) {
            int val = nums1[i];

            int cnt1 = 0;
            while (i < nums1.size() && nums1[i] == val) {
                cnt1++;
                i++;
            }

            int left = lower_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
            int right = upper_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
            int cnt2 = right - left;

            int times = min(cnt1, cnt2);
            while (times--) ans.push_back(val);
        }

        return ans;
    }
};
