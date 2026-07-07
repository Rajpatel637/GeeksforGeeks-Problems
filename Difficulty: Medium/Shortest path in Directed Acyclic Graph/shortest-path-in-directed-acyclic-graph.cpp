#include <stack>
#include <bits/stdc++.h>


void getAdj(vector<vector<int>> &edges,vector<vector<pair<int,int>>> &adjList){
    for(int i = 0; i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        
        adjList[u].push_back({v,weight});
    }
}

void topoSort(int node,stack<int> &st,vector<bool> &visited, vector<vector<pair<int,int>>> &adjList){
    
    visited[node] = true;
    
    for(auto i : adjList[node]){
        if(!visited[i.first]){
            topoSort(i.first,st,visited,adjList);
        }
    }
    
    st.push(node);
}

void getShortestPath(int src,stack<int> &st,vector<int> &dist,vector<vector<pair<int,int>>> &adjList){
    
    dist[src] = 0;
    
    while(!st.empty()){
        int topNode = st.top();
        st.pop();
        
        if(dist[topNode] != INT_MAX){
            for(auto i : adjList[topNode]){
                if(dist[topNode] + i.second < dist[i.first]){
                    dist[i.first] = dist[topNode] + i.second;
                }
            }
        }
    }
}



class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adjList(V);
        vector<bool> visited(V);
        vector<int> dist(V);
        stack<int> st;
        
        //adjList -->
        
        getAdj(edges,adjList);
        
        // dist intialize as INT_MAX
        
        for(int i = 0; i < V;i++){
            dist[i] = INT_MAX;
        }
        
        // find topological sort
        
        for(int i = 0; i < V;i++){
            if(!visited[i]){
                topoSort(i,st,visited,adjList);
            }
        }
        
        // find Shortest Path
        
        int src = 0;
        
        getShortestPath(src,st,dist,adjList);
        
        // Intialize  remanining INT_MAX node to -1 
        
        for(int i = 0; i < V;i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
