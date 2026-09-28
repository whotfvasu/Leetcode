class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mpp;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = i;
            }
            else{
                mpp[s[i]]=INT_MAX;
            }
        }
        int ans = INT_MAX;
        for(auto x: mpp){
            int ind = x.second;
            ans = min(ans,ind);
        }
        return ans == INT_MAX? -1:ans;
    }
};