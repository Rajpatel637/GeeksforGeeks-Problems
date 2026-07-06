void getAdj(vector<vector<int>> & edges, vector<vector<int>> &adjList) {
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}

bool checkCycle(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
	
	stack<pair<int, int>> st;
	st.push({node, -1});
	visited[node] = true;
	
	while (!st.empty()) {
		int element = st.top().first;
		int parent = st.top().second;
		st.pop();
		
		for (auto i : adjList[element]) {
			
			if (!visited[i]) {
				visited[i] = true;
				st.push({i, element});
			}
			else if (i != parent) {
				return true;
			}
		}
		
	}
	
	return false;
	
}

class Solution {
	public:
	bool isCycle(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adjList(V);
		vector<bool> visited(V);
		
		getAdj(edges, adjList);
		
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				
				bool ans = checkCycle(i, adjList, visited);
				if (ans)
					return true;
			}
		}
		
		return false;
		
	}
};
