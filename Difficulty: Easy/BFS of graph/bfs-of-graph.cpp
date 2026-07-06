#include <queue>

void getBFS( vector<int> &ans,vector<bool> &visited,vector<vector<int>> &adj,int node){
    
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        ans.push_back(temp);
        
        for(auto i : adj[temp]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}





class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> visited(n,false);
        vector<int> ans;
        
        getBFS(ans,visited,adj,0);
        
        return ans;
    }
};