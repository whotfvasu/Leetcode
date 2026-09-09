class Solution {
public:
    bool sahi(vector<int>& have, vector<int>& needed) {
        for(int i = 0; i < 128; i++) {
            if(have[i] < needed[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> have(128);
        vector<int> needed(128);

        for(char c : t) {
            needed[c]++;
        }

        int left = 0;
        int res = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.length(); right++) {

            have[s[right]]++;

            while(sahi(have, needed)) {

                int len = right - left + 1;

                if(len < res) {
                    res = len;
                    start = left;
                }

                have[s[left]]--;
                left++;
            }
        }

        if(res == INT_MAX)
            return "";

        return s.substr(start, res);
    }
};