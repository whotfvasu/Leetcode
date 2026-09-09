class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int ans = 0;
        int maxFreq = 0;

        vector<int> cnt(26, 0);

        for (int right = 0; right < s.length(); right++) {

            cnt[s[right] - 'A']++;

            maxFreq = max(maxFreq, cnt[s[right] - 'A']);

            int len = right - left + 1;

            if (len - maxFreq > k) {
                cnt[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};