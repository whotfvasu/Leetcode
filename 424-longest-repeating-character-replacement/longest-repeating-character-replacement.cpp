class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left=0,ans=INT_MIN;
        vector<int> cnt(256);
        int len = 0;
        for(int right=0;right<n;right++){
            cnt[s[right]]++;
            len = right-left+1;
            int maxEl = *max_element(cnt.begin(), cnt.end());
            int diff = len-maxEl;
            while(diff>k){
                cnt[s[left]]--;
                left++;
                len--;
                diff--;
            }
            if(diff<=k){
                ans = max(ans,len);
            }
        }
        return ans;
    }
};