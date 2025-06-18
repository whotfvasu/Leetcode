class Solution {
public:
    string filter(string& s){
        string t;
        for(char ch: s){
            if(isalnum(ch)){
                t+=tolower(ch);
            }
        }
        return t;
    }
    bool isPalindrome(string s) {
        
        s = filter(s);string t = s;
        reverse(s.begin(),s.end());
        if(t==s) return true;
        return false;
        
    }
};