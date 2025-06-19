class Solution {
public:
    int longestPalindrome(string s) {

        map<char,int> mpp;
        int n = s.length();
        if(n==1) return 1;
        for(char c: s){
            mpp[c]++;
        }
        int sum = 0;
        for(auto it: mpp){
            sum+=it.second/2;
        }
        if(sum*2==n) return sum*2;
        else return sum*2+1;
    }
};