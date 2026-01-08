class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search in larger array
        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0;

        while (i < nums1.size()) {
            int val = nums1[i];

            // skip duplicates in nums1
            while (i < nums1.size() && nums1[i] == val)
                i++;

            // binary search in nums2
            if (binary_search(nums2.begin(), nums2.end(), val)) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
