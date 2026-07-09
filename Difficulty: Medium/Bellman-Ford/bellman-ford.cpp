class Solution {
	public:
	vector<int> bellmanFord(int V, vector<vector<int>> & edges, int src) {
		
		vector<int> dist(V, 1e8);
		dist[src] = 0;
		
		for (int i = 0; i < V-1; i++) {
			for (int j = 0; j < edges.size(); j++) {
				int u = edges[j][0];
				int v = edges[j][1];
				int weight = edges[j][2];
				
				if (dist[u] != 1e8 && dist[u] + weight < dist[v]) {
					dist[v] = dist[u] + weight;
				}
			}
		}
		
		// negative cycle
		
		bool flag = 0;
		for (int j = 0; j < edges.size(); j++) {
			int u = edges[j][0];
			int v = edges[j][1];
			int weight = edges[j][2];
			
			if (dist[u] != 1e8 && dist[u] + weight < dist[v]) {
				flag = 1;
			}
		}
		
		if(flag) return {-1};
		return dist;
	}
};
