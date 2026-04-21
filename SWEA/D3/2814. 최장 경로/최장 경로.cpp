#include <iostream>
#include <vector>

using namespace std;


int dfs(vector<vector<int>> graph, vector<bool>& visit, int now) {
	visit[now] = false;

	int max_len = 1;
	for (int next : graph[now]) {
		if (visit[next]) {
			max_len = max(max_len, dfs(graph, visit, next) + 1);
		}
	}

	visit[now] = true;
	return max_len;
}

int main() {

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> graph(n + 1);
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int answer = 0;
		vector<bool> visit(n + 1, true);
		for (int j = 1; j <= n; j++) {
			answer = max(answer, dfs(graph, visit, j));
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}