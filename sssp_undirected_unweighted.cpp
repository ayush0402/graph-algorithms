#include <bits/stdc++.h>
using namespace std;

vector <int> arr[100001];
int vis[100001];
int dist[100001];

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	int src = 1;
	queue <int> q;
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto it : arr[node]) {
			if (!vis[it]) {
				q.push(it);
				dist[it] = dist[node] + 1;
				vis[it] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	cout << endl;
}
