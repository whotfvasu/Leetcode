// class Solution {
// public:
    

//         vector<vector<int>> g;
//         vector<int> vis;
//         int cnt = 0;
//         void dfs(int node) {
//             vis[node] = 1;
//             for (auto v : g[node]) {
//                 if (!vis[v]) {
//                     dfs(v);
//                 }
//             }
//         }
//         int findCircleNum(vector<vector<int>> & isConnected) {
//             int n = isConnected.size();
//             g.resize(n + 1);
//             vis.resize(n + 1);
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0;j < n; j++) {
//                     if (isConnected[i][j] == 1) {
//                         g[i + 1].push_back(j + 1);
//                         g[j + 1].push_back(i + 1);
//                     }
//                 }
//             }
//             for (int i = 1; i <= n; i++) {
//                 if (!vis[i]) {
//                     cnt++;
//                     dfs(i);
//                 }
//             }
//             return cnt;
//         }
    
// };

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};