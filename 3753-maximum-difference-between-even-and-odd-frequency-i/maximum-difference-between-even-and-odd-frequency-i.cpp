class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int maxeven = INT_MIN;
        int maxodd = INT_MIN;
        int mineven = INT_MAX;
        int minodd = INT_MAX;
        
        for(auto it: mpp){
            if(it.second%2==0){
                if(it.second>maxeven) maxeven = it.second;
                if(it.second<mineven) mineven = it.second;
            }
           else{
                if(it.second>maxodd) maxodd = it.second;
                if(it.second<minodd) minodd = it.second;
            }
        }
        
        
        int ans2 = maxodd - mineven;
        return ans2;
    }
};