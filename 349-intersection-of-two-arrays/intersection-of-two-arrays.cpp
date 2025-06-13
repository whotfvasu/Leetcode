class Solution {
public:
    vector<int> intersection(vector<int>& v1, vector<int>& v2) {
        vector<int> result;
        set<int> st1(v1.begin(),v1.end());
        set<int> st2(v2.begin(),v2.end());
        for( auto nums: st1){
            if(st2.find(nums)!= st2.end()){
                result.push_back(nums);
            }
        }
        return result;
    }
};