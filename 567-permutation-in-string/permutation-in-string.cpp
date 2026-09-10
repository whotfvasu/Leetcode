class Solution {
public:
    bool extra(vector<int> &have, vector<int> &needed){
        for(int i=0;i<256;i++){
            if(have[i]>needed[i]) return true;
        }
        return false;
    }
    bool check(vector<int> &have, vector<int> &needed){
        for(int i=0;i<256;i++){
            if(needed[i]!=have[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> have(256);
        vector<int> needed(256);

        for(char c : s1) {
            needed[c]++;
        }

        int left = 0;

        for(int right=0;right<s2.size();right++){
            have[s2[right]]++;
            while(extra(have,needed)){
                have[s2[left]]--;
                left++;
            }
            if(check(have,needed)==true) return true;
        }
        return false;
    }
};