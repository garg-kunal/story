#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{

	int n, m;
	cin >> n >> m;
 
	vector<vector<int>> edges(m);
 
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = {u, v, w};
	}
 
	vector<int> dis(n + 1, 1e8);
 
	
	dis[1] = 0;
 
	for (int i = 0; i < n - 1; i++) {
		
		for (int j = 0; j < m; j++) {
			
			int u, v, w;
			u = edges[j][0];
			v = edges[j][1];
			w = edges[j][2];
 
			if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
		}
	}
 
	for (int j = 0; j < m; j++) {
		
		int u, v, w;
		u = edges[j][0];
		v = edges[j][1];
		w = edges[j][2];
 
		if (dis[v] > dis[u] + w) {
			cout << "Negative cycle detected";
			return 0;
		}
	}
 
	for (int i = 1; i <= n; i++) {
		cout << i << " --> " << dis[i] << '\n';
	}
 
}
