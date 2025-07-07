class Solution {
public:
    // vector<pair<char,int>> helper1(string s){
    //     vector<pair<char,int>> v;
    //     int n = s.length();
    //     int i=0;
    //     while(i<n){
    //         int cnt = 1;
    //         while(i+1<n && s[i]==s[i+1]){
    //             i++;
    //             cnt++;
    //         }
    //         v.push_back({s[i],cnt});
    //         i++;
    //     }
    //     return v;
    // }
    // string helper2(vector<pair<char,int>> v){
    //     string s = "";
    //     int n = v.size();
    //     for(auto it: v){
    //         s+= to_string(it.second);
    //         s+= it.first;
    //     }
    //     return s;
    // }
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string res = "";
        int i = 0;

        while (i < prev.size()) {
            int count = 1;
            while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                i++;
                count++;
            }
            res += to_string(count) + prev[i];
            i++;
        }

        return res;
    }
};