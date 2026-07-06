#include <stack>

void getTopoSortDFS(int node,stack<int> &st,vector<bool> &visited,vector<vector<int>> &adjList){
    visited[node] = true;
    
    
    for(auto i : adjList[node]){
        if(!visited[i]){
            getTopoSortDFS(i,st,visited,adjList);
        }
    }
    
    st.push(node);
}

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        vector<bool> visited(V);
        stack<int> st;
        vector<int> ans;
        
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
        }
        
        for(int i = 0; i < V;i++){
            if(!visited[i]){
                getTopoSortDFS(i,st,visited,adjList);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
        
        
    }
};