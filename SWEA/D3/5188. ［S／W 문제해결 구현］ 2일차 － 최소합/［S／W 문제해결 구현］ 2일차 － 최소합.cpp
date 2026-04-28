#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<int> dx = { 0, 1 };
vector<int> dy = { 1, 0 };

int main() {

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		vector<vector<long long>> square(n, vector<long long>(n));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> square[j][k];
			}
		}

		// 방문 비용 저장용 2차원 배열
		vector<vector<long long>> answer(n, vector<long long>(n, LLONG_MAX));
		answer[0][0] = square[0][0];

		// bfs 이동 큐
		queue<pair<int, int>> que;
		que.push({0, 0});

		while (!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();

			// 이동할 수 있는 방향으로 이동
			for (int j = 0; j < dx.size(); j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				// 다음 방향 정보를 큐에 추가
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (answer[ny][nx] > answer[y][x] + square[ny][nx]) {
						answer[ny][nx] = answer[y][x] + square[ny][nx];
						que.push({ ny, nx });
					}
				}
			}
		}

		cout << "#" << i + 1 << " " << answer[n - 1][n - 1] << endl;
	}
}