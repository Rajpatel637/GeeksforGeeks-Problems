#include <algorithm>
bool cmp(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(vector<int> &parent, int node) {
	if (parent[node] == node) {
		return node;
	}
	
	return parent[node] = findParent(parent, parent[node]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v) {
	if (rank[u] < rank[v]) {
		parent[u] = v;
	}
	else if (rank[v] < rank[u]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}
}

class Solution {
	public:
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		sort(edges.begin(), edges.end(), cmp);
		
		vector<int> parent(V);
		vector<int> rank(V);
		
		makeSet(parent, rank, V);
		
		int minWeight = 0;
		
		for (int i = 0; i < edges.size(); i++) {
			int u = findParent(parent, edges[i][0]);
			int v = findParent(parent, edges[i][1]);
			
			int weight = edges[i][2];
			
			if (u != v) {
				minWeight += weight;
				unionSet(parent, rank, u, v);
			}
		}
		
		return minWeight;
		
	}
};
