class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);

        numRows--;

        while(numRows--){
            int n = temp.size();

            vector<int> newa(n+1);

            newa[0] = 1;
            newa[n] = 1;

            for(int i=1;i<=n-1;i++){
                newa[i] = temp[i-1] + temp[i];
            }

            ans.push_back(newa);

            temp = newa;
        }
        return ans;
    }
};