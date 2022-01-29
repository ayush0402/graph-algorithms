#include <bits/stdc++.h>
using namespace std;


vector <int> arr[100001];
int vis[100001];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	queue <pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			q.push({i, 0});

			while (!q.empty()) {
				int node = q.front().first;
				int parent = q.front().second;
				q.pop();
				for (auto it : arr[node]) {
					if (!vis[it]) {
						vis[it] = 1;
						q.push({it, node});
					}
					else if (it != parent) {
						cout << "cycle found" << endl; return 0;
					}
				}
			}
			cout << "no cycle found" << endl;
		}
	}
}
