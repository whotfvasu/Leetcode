class Solution {
public:

    void recur(int node, vector<vector<int>> &graph, vector<int> &component, vector<vector<int>>&ans){
        component.push_back(node);
        if(node == graph.size()-1){
            ans.push_back(component);
            
        }else{
            for(auto i: graph[node]){
                recur(i, graph, component, ans);
            }
        }
        component.pop_back();
  
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;

        vector<int> component;
        
        recur(0, graph, component, ans);
        return ans;
    }
};