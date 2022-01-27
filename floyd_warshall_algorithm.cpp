#include <bits/stdc++.h>
using namespace std;


vector <pair<int, int>> arr[501];
ll dist[501][501];

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)dist[i][j] = 0;
			else dist[i][j] = 1e18;
		}
	}

	// Works on directed as well as undirected graphs.

	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		arr[u].push_back({v, w});
		arr[v].push_back({u, w});
		if (dist[u][v] > w) {
			dist[u][v] = w;
			dist[v][u] = w;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		if (dist[a][b] == 1e18)cout << -1 << endl;
		else cout << dist[a][b] << endl;
	}

}
