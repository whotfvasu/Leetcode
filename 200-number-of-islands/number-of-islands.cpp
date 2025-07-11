class Solution {
    void solve(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';

        if(i + 1 < grid.size())  solve(grid, i + 1, j);
        if(i - 1 >= 0) solve(grid, i - 1, j);

        if(j + 1 < grid[i].size()) solve(grid, i, j + 1);
        if(j - 1 >= 0 ) solve(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    solve(grid, i, j);
                }
            }
        }

        return ans;
    }
};