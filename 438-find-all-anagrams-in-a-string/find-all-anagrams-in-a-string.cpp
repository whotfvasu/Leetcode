class Solution {
public:
    bool extra(vector<int>& have, vector<int>& needed) {
        for (int i = 0; i < 26; i++) {
            if (have[i] > needed[i])
                return true;
        }
        return false;
    }
    bool check(vector<int>& have, vector<int>& needed) {
        for (int i = 0; i < 26; i++) {
            if (needed[i] != have[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> have(26);
        vector<int> needed(26);
        vector<int> ans;

        for(char c : p) {
            needed[c-'a']++;
        }

        int left = 0;

        for(int right=0;right<s.size();right++){
            have[s[right]-'a']++;
            while(extra(have,needed) && left<right){
                have[s[left]-'a']--;
                left++;
            }
            if(check(have,needed)==true) ans.push_back(left);
        }
        return ans;

    }
};