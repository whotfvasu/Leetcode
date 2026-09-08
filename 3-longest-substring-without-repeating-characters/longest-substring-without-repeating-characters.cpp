class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            while (mp.size() < right-left+1) {
                mp[s[left]]--;

                if (mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            if(mp.size() == right-left+1){
                ans = max(ans, right - left + 1);
            }
        }

        return ans;

    }
};