
void dfsTraversal(int node,vector<int> &ans,vector<bool> &visited,vector<vector<int>> &adj){
    visited[node] = true;
    ans.push_back(node);
    
    for(auto i : adj[node]){
        if(!visited[i]){
            visited[i] = true;
            dfsTraversal(i,ans,visited,adj);
        }
    }
}


class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
         vector<bool> visited(n);
         vector<int> ans;
        for(int i = 0; i < n;i++){
            if(!visited[i]){
                dfsTraversal(i,ans,visited,adj);
            }
        }
        
         return ans;
        
    }
};