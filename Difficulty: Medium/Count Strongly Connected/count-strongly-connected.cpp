


void dfs(int node,stack<int> &st,vector<bool> &visited,vector<vector<int>>& adjList){
    visited[node] = true;
    
    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(i,st,visited,adjList);
        }
    }
    
    st.push(node);
}

void revDFS(int node,vector<bool> &visited,vector<vector<int>> & transpose){
    visited[node] = true;
    
    for(auto i : transpose[node]){
        if(!visited[i]){
            revDFS(i,visited,transpose);
        }
    }
}



class Solution {
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        
        // created a adjList 
        
        vector<vector<int>> adjList(V);
        
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
        }
        
        // topo sort
        
        stack<int> st;
        vector<bool> visited(V);
        
        
        for(int i = 0; i < V;i++){
            if(!visited[i]){
                dfs(i,st,visited,adjList);
            }
        }
        
        // transpose 
        
        vector<vector<int>> transpose(V);
        
        for(int i = 0; i < V;i++){
            visited[i] = 0;
            
            for(auto j : adjList[i]){
                transpose[j].push_back(i);
            }
        }
        
        
        // revDFS
        
        int cnt = 0;
        
        while(!st.empty()){
            int topNode = st.top();
            st.pop();
            
            if(!visited[topNode]){
                cnt++;
                revDFS(topNode,visited,transpose);
            }
        }
        
        return cnt;
        
        
        
    }
};