class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adjList(V);
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> st;
        
        // creating adjList
        
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }
        
        // finding shortest path using dijkstra's Algo
        
        dist[src] = 0;
        
        st.insert({0,src});
        
        while(!st.empty()){
            
            auto top = *st.begin();
            
            int nodeDistance = top.first;
            int topNode = top.second;
            
            st.erase(top);
            
            for(auto neighbour : adjList[topNode]){
                if(dist[topNode] + neighbour.second < dist[neighbour.first]){
                    
                    auto record = st.find({dist[neighbour.first],neighbour.first});
                    
                    if(record != st.end()) st.erase(record);
                    
                    dist[neighbour.first] = dist[topNode] + neighbour.second;
                    
                    st.insert({dist[neighbour.first],neighbour.first});
                }
            }
        }
        
        
        return dist;
        
    }
};