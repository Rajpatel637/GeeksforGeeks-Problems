
void apDFS(int node,int parent,int &timer,vector<int> &disc,
vector<int>&low,vector<bool>&visited,vector<int> adj[],vector<int> &ans){
     
     visited[node] = true;
     disc[node] = low[node] = timer++;
     int child = 0;
     
     
     for(auto neighbour : adj[node]){
         if(parent == neighbour) continue;
         
        if(!visited[neighbour]){
             apDFS(neighbour,node,timer,disc,low,visited,adj,ans);
             
             low[node] = min(low[node],low[neighbour]);
             
             if(low[neighbour] >= disc[node] && parent != -1){
                 ans[node] = 1;
             }
             child++;
             
        }
        else {
            low[node] = min(low[node],disc[neighbour]);
        }
    }
    
    if(child > 1 && parent == -1){
         ans[node] = 1;
    }
    
}


class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        
        int timer = 0;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        vector<bool> visited(V);
        vector<int> ans(V,0);
        vector<int> result;
        
        for(int i = 0; i < V;i++){
            if(!visited[i]){
                apDFS(i,-1,timer,disc,low,visited,adj,ans);
            }
        }
        
        for(int index = 0; index < V;index++){
            if(ans[index] == 1){
                result.push_back(index);
            }
        }
        if(result.size() == 0){
            result.push_back(-1);
            return result;
        }
        return result;
        
        
    }
};