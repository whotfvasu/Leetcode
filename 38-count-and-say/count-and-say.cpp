class Solution {
public:
    vector<pair<char,int>> helper1(string s){
        vector<pair<char,int>> v;
        int n = s.length();
        int i=0;
        while(i<n){
            int cnt = 1;
            while(i+1<n && s[i]==s[i+1]){
                i++;
                cnt++;
            }
            v.push_back({s[i],cnt});
            i++;
        }
        return v;
    }
    string helper2(vector<pair<char,int>> v){
        string s = "";
        int n = v.size();
        for(auto it: v){
            s+= to_string(it.second);
            s+= it.first;
        }
        return s;
    }
    string countAndSay(int n) {
        string s = "1";
        unordered_map<int,int> mpp;
        n--;
        while(n--){
            vector<pair<char,int>> v =helper1(s);
            s = helper2(v);
        }
        return s;
    }
};