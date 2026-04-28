#include <iostream>
#include <vector>
#include <queue>

#define TC 10

using namespace std;

int main() {
	
	for (int i = 0; i < TC; i++) {
		int tc_num, n;
		cin >> tc_num >> n;

		// 간선 생성 (그래프 생성)
		vector<vector<int>> graph(n + 1);
		for (int j = 0; j < n; j++) {
			int v1, v2;
			cin >> v1 >> v2;

			graph[v1].push_back(v2);
		}

		// 중복 연산 최소화를 위해 visit 사용
		vector<bool> visit(n + 1, false);
		visit[0] = true;

		// 시작 좌표 0에서 시작
		queue<int> que;
		que.push(0);

		// que가 비거나 도착지에 도착하면 종료
		int answer = 0;
		while (!que.empty() && !answer) {
			int now = que.front();
			que.pop();

			// 다음 좌표 탐색
			for (int next : graph[now]) {
				// 다음 좌표가 99(도착지)일 경우 종료
				if (next == 99) {
					answer = 1;
					break;
				}

				// 다음 좌표가 방문한 적이 없다면 que에 넣고 방문 처리
				if (!visit[next]) {
					visit[next] = true;
					que.push(next);
				}
			}
		}

		cout << "#" << tc_num << " " << answer << endl;
	}
}