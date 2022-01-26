#include <bits/stc++.h>
using namespace std;

vector <int> arr[100001];
int vis[100001];

void bfs(int v) {
	queue <int> q;
	q.push(v);
	vis[v] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto it : arr[node]) {
			if (!vis[it]) {
				vis[it] = 1;
				q.push(it);
			}
		}
	}

}

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i])bfs(i);
	}

}
