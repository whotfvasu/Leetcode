class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        vector<int> v(26);
        for(int i=0;i<n;i++){
            v[text[i]-'a']++;
        }
        int cntb = v[1];
        int cnta = min(cntb,v[0]);
        int cntl = min(cnta,v['l'-'a']/2);
        int cnto = min(cntl,v['o'-'a']/2);
        int cntn = min(cnto,v['n'-'a']);

        return cntn;
    }
};