#include <bits/stdc++.h>
using namespace std;

stack <int> topo;
vector <int> arr[100001];
int vis[100001];

void findTopoSort(int node) {
	vis[node] = 1;
	for (auto child : arr[node]) {
		if (!vis[child])findTopoSort(child);
	}
	st.push(node);
}

int main() {
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i])findTopoSort(i);
	}

	while (!topo.empty()) {
		cout << topo.top() << ' ';
		topo.pop();
	}
}
