#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, -1, 0, 1 };

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		// 농작물 입력
		vector<vector<int>> area(n, vector<int>(n));
		for (int j = 0; j < n; j++) {
			string price;
			cin >> price;

			for (int k = 0; k < n; k++) {
				area[j][k] = price[k] - '0';
			}
		}

		int answer = 0;

		// 시작점 방문 표시
		vector<vector<bool>> visit(n, vector<bool>(n, false));
		visit[n / 2][n / 2] = true;

		queue<pair<int, int>> que;
		que.push({n / 2, n / 2});

		// 방문할 영역의 개수 계산
		int area_count = 1;
		for (int j = 1; j <= n; j += 2) {
			area_count += 4 * (j / 2);
		}

		for (int j = 0; j < area_count; j++) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			answer += area[x][y];
			
			for (int j = 0; j < dx.size(); j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				// 범위에서 벗어나는 경우
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
					continue;
				}

				// 방문하지 않은 경우
				if (!visit[nx][ny]) {
					visit[nx][ny] = true;
					que.push({ nx, ny });
				}
			}
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}