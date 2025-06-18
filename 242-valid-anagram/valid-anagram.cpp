class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n!=m) return false;
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp.find(t[i])!=mpp.end()){
                mpp[t[i]]--;
                if(mpp[t[i]]==0){
                    mpp.erase(t[i]);
                }
            }
            else return false;
        }
        return true;
    }
};