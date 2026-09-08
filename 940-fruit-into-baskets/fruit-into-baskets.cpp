class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int ans = -1;

        unordered_map<int, int> mp;

        for (int right = 0; right < n; right++) {
            mp[fruits[right]]++;

            if (mp.size() > 2) {
                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);

                left++;
            }

            if (mp.size() <= 2) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};