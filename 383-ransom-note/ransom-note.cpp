class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mpp;
        int n = ransomNote.length();
        int m = magazine.length();
        for(char c: magazine){
            mpp[c]++;
        }
        for(char c: ransomNote){
            if(mpp.find(c)!=mpp.end()){
                mpp[c]--;
                if(mpp[c]==0) mpp.erase(c);
            }
            else return false;
        }
        return true;
    }
};