class Solution {
public:
    bool check(int left, string& s, map<string, int>& needed, int wordLength,
               int totalWords) {
        map<string, int> mpp;

        for (int x = 0; x < totalWords * wordLength; x += wordLength) {
            mpp[s.substr(left + x, wordLength)]++;
        }

        return mpp == needed;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();

        map<string, int> needed;
        for (auto& word : words) {
            needed[word]++;
        }

        int totalLength = words.size() * wordLength;

        vector<int> ans;

        for (int left = 0; left + totalLength <= s.length(); left++) {
            if (check(left, s, needed, wordLength, words.size())) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};