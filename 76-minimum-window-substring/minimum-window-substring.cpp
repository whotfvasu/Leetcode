class Solution {
public:
    bool sahi(vector<int> &have, vector<int> &needed){
        for(int i=0;i<256;i++){
            if(have[i] < needed[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> have(256); vector<int> needed(256);
        for(int i=0;i<t.length();i++){
            needed[t[i]]++;
        }
        int left = 0, res = INT_MAX, start = 0;

        for(int right=0; right<s.length(); right++){
            have[s[right]]++;
            while(sahi(have,needed)){
                
                int len = right-left+1;
                if(res>len){
                    res = len;
                    start = left;
                }
                have[s[left]]--;
                left++;
            }
        }
        if(res == INT_MAX)
            return "";
        return s.substr(start,res);

    }
};