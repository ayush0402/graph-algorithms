#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> arr[100001];
int vis[100001];
ll dist[100001];

int main() {
	int n, m; cin >> n >> m;
// Can be used for both directed as well as undirected graphs.
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		arr[u].push_back(make_pair(v, w));
		arr[v].push_back(make_pair(u, w));
	}

	for (int i = 1; i <= n; i++)dist[i] = 1e18;

	int src = 1;
	dist[src] = 0;

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

	pq.push({0, src});

	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();
		if (!vis[node]) {
			vis[node] = 1;
			for (auto it : arr[node]) {
				if (dist[it.first] > dist[node] + it.second) {
					dist[it.first] = dist[node] + it.second;
					pq.push({dist[it.first], it.first});
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
}
