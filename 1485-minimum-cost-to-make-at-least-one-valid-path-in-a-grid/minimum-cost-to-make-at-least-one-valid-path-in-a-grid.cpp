class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        deque<pair<int,int>> dq;
        dq.push_back({0,0});
        dist[0][0] = 0;
        while(!dq.empty()){
            int x = dq.front().first, y = dq.front().second;
            dq.pop_front();
            for(int k=0;k<4;k++){
                int i = dx[k] + x, j = dy[k] + y;
                int w = (k + 1 == grid[x][y]) ? 0 : 1; 
                if (i >= 0 && i < n && j >= 0 && j < m && dist[i][j] > dist[x][y] + w) {
				dist[i][j] = dist[x][y] + w;
				if (w)dq.push_back({i, j});
				else dq.push_front({i, j});
			}
            }
        }
        return dist[n - 1][m - 1];
    }
};