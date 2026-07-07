class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adjList(V);
        vector<bool> visited(V);
        vector<int> parent(V,-1);
        int cnt = 0;
        
        
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto i : adjList[frontNode]){
                if(!visited[i]){
                    visited[i] = true;
                    parent[i] = frontNode;
                    q.push(i);
                }
            }
        }
        
        int currentNode = dest;
        
        while(currentNode != src){
            if(currentNode == -1) {
                cnt = -1;
                break;
            }
            cnt++;
            currentNode = parent[currentNode];
        }
       
       return cnt;
        
        
        
    }
};
