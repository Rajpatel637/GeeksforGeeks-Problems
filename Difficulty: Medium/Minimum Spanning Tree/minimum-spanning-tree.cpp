class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adjList(V);
        
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }
        
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V);
        vector<int> parent(V,-1);
        
        key[0] = 0;
        parent[0] = -1;
        
        for(int i = 0; i < V;i++){
            int mini = INT_MAX;
            int u ;
            
            for(int vertex = 0; vertex < V;vertex++){
                if(!mst[vertex] && key[vertex] < mini){
                    u = vertex;
                    mini = key[vertex];
                }
            }
            
            mst[u] = true;
            
            
            for(auto it : adjList[u]){
                int v = it.first;
                int weight = it.second;
                
                if(!mst[v] && weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }
        
        int minCost = 0;
        
        for(auto i : key){
            minCost += i;
        }
        
        return minCost;
        
    }
};