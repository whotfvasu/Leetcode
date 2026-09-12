class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;

        unordered_map<string, int> needed;

        for (auto &word : words) {
            needed[word]++;
        }

        vector<int> ans;

        // There are wordLength possible alignments
        for (int offset = 0; offset < wordLength; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset;
                 right + wordLength <= s.length();
                 right += wordLength) {

                string word = s.substr(right, wordLength);

                // Word isn't present in words
                if (!needed.count(word)) {
                    window.clear();
                    count = 0;
                    left = right + wordLength;
                    continue;
                }

                window[word]++;
                count++;

                // Too many occurrences of this word
                while (window[word] > needed[word]) {
                    string leftWord = s.substr(left, wordLength);

                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }

                // We have exactly all words
                if (count == totalWords) {
                    ans.push_back(left);

                    // Move left forward to look for another answer
                    string leftWord = s.substr(left, wordLength);
                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }
            }
        }

        return ans;
    }
};



// class Solution {
// public:
//     bool check(int left, string& s, map<string, int>& needed, int wordLength,
//                int totalWords) {
//         map<string, int> mpp;

//         for (int x = 0; x < totalWords * wordLength; x += wordLength) {
//             mpp[s.substr(left + x, wordLength)]++;
//         }

//         return mpp == needed;
//     }
//     vector<int> findSubstring(string s, vector<string>& words) {
//         int wordLength = words[0].size();

//         map<string, int> needed;
//         for (auto& word : words) {
//             needed[word]++;
//         }

//         int totalLength = words.size() * wordLength;

//         vector<int> ans;

//         for (int left = 0; left + totalLength <= s.length(); left++) {
//             if (check(left, s, needed, wordLength, words.size())) {
//                 ans.push_back(left);
//             }
//         }

//         return ans;
//     }
// };