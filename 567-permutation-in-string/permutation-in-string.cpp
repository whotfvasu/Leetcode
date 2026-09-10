class Solution {
public:
    bool extra(vector<int> &have, vector<int> &needed){
        for(int i=0;i<26;i++){
            if(have[i]>needed[i]) return true;
        }
        return false;
    }
    bool check(vector<int> &have, vector<int> &needed){
        for(int i=0;i<26;i++){
            if(needed[i]!=have[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> have(26);
        vector<int> needed(26);

        for(char c : s1) {
            needed[c-'a']++;
        }

        int left = 0;

        for(int right=0;right<s2.size();right++){
            have[s2[right]-'a']++;
            while(extra(have,needed)){
                have[s2[left]-'a']--;
                left++;
            }
            if(check(have,needed)==true) return true;
        }
        return false;
    }
};