#include <iostream>
#include <vector>

using namespace std;


/** 최대 경로 길이 계산 */
int dfs(vector<vector<int>> graph, vector<bool>& visit, int now) {
	visit[now] = false; // 방문 표시

	// 현재 노드 기준 다음 노드들에 대해 최대 경로 길이 계산
	int max_len = 1;
	for (int next : graph[now]) { 
		if (visit[next]) { 
			max_len = max(max_len, dfs(graph, visit, next) + 1);
		}
	}

	// 출발선이 다른 노드들에서도 방문할 수 있도록 방문 표시 해제
	visit[now] = true; 
	return max_len;
}


int main() {

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n >> m;

		// 각 간선을 Linked List 형태로 저장
		vector<vector<int>> graph(n + 1);
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// dfs를 통해 최대 경로 길이 계산
		int answer = 0;
		vector<bool> visit(n + 1, true);
		for (int j = 1; j <= n; j++) {
			answer = max(answer, dfs(graph, visit, j));
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}