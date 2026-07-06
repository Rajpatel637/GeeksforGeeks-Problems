
bool checkCycleDFS(int node,vector<bool> &visited,vector<bool> &dfsVisited,vector<vector<int>> &adjList){
    visited[node] = true;
    dfsVisited[node] = true;
    
    
    for(auto i : adjList[node]){
        if(!visited[i]){
            bool result = checkCycleDFS(i,visited,dfsVisited,adjList);
            if(result) return true;
        }
        else if(dfsVisited[i]){
            return true;
        }
    }
    
    dfsVisited[node] = false;
    return false;
    
}


class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adjList(V);
        vector<bool> visited(V);
        vector<bool> dfsVisited(V);
        
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
        }
        
        for(int i = 0; i < V;i++){
            if(!visited[i]){
                bool detectCycle = checkCycleDFS(i,visited,dfsVisited,adjList);
                if(detectCycle) return true;
            }
        }
        
        return false;
        
    }
};