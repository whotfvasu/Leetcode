class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rnmpp(26);
        vector<int> mmpp(26);
        for(int i=0;i<ransomNote.length();i++){
            rnmpp[ransomNote[i]-'a']++;
        }
        for(int i=0;i<magazine.length();i++){
            mmpp[magazine[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(rnmpp[i]>mmpp[i]) return false;
        }
        return true;
    }
};