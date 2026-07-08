bool getBridgeDFS(int node, int parent, int timer, int c, int d, vector<int> &disc, vector<int> &low,
vector<bool> &visited, vector<vector<int>> &adjList) {
	
	visited[node] = true;
	disc[node] = low[node] = timer++;
	
	for (auto neighbour : adjList[node]) {
		if (parent == neighbour)
			continue;
		
		if (!visited[neighbour]) {
			bool res = getBridgeDFS(neighbour, node, timer,c,d, disc, low, visited, adjList);
			
			if (res)
				return true;
			
			low[node] = min(low[node], low[neighbour]);
			
			if (low[neighbour] > disc[node]) {
				if ((node == c && neighbour == d) || (node == d && neighbour == c))
					return true;
			}
		}
		else {
			low[node] = min(low[node], disc[neighbour]);
		}
	}
	
	return false;
}

class Solution {
	public:
	bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
		vector<vector<int>> adjList(V);
		
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		
		int timer = 0;
		int parent = -1;
		vector<int> disc(V, -1);
		vector<int> low(V, -1);
		vector<bool> visited(V);
		
		for (int i = 0 ; i < V; i++) {
			if (!visited[i]) {
				bool ans = getBridgeDFS(i, parent, timer, c, d, disc, low, visited, adjList);
				if (ans)
					return true;
			}
		}
		
		return false;
	}
};
