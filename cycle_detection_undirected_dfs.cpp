#include <bits/stdc++.h>
using namespace std;

vector <int> arr[100001];
int vis[100001];

bool findCycle(int node, int parent) {
	vis[node] = 1;
	for (auto child : arr[node]) {
		if (!vis[child]) {
			if (findCycle(child, node))return true;
		}
		else if (child != parent)return true;
	}
	return false;
}

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (findCycle(i, 0)) {
				cout << "cycle found" << endl; return;
			}
		}
	}

	cout << "cycle not found" << endl;
}
