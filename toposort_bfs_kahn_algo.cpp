#include <bits/stdc++.h>
using namepace std;

vector <int> arr[100001];
int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
	}

	vector <int> indegree(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (auto j : arr[i]) {
			indegree[j]++;
		}
	}

	queue <int> q;
	vector <int> topo;

	for (int i = 1; i <= n; i++) {
		if (!indegree[i])q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for (auto it : arr[node]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				q.push(it);
			}
		}
	}

	for (int i = 0; i < topo.size(); i++) {
		cout << topo[i] << ' ';
	}
}
