class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int cnt = 0;
        int finalcnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                cnt=0;
            }
            else{
                cnt++;
                finalcnt = cnt;
            }
        }
        return finalcnt;
    }
};