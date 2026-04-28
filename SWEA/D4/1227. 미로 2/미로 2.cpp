#include <iostream>
#include <vector>
#include <queue>

#define MAZE_SIZE 100
#define TEST_CASE 10

using namespace std;

vector<int> dx = { 1, -1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };

int main() {
	vector<vector<long long>> maze(MAZE_SIZE, vector<long long>(MAZE_SIZE));

	for (int i = 0; i < TEST_CASE; i++) {
		int tc_num;
		cin >> tc_num;

		int y, x;
		for (int j = 0; j < MAZE_SIZE; j++) {
			string temp;
			cin >> temp;

			for (int k = 0; k < MAZE_SIZE; k++) {
				maze[j][k] = temp[k] - '0';

				if (maze[j][k] == 2) {
					y = j;
					x = k;
				}
			}
		}

		// 시작점 방문 처리
		maze[y][x] = 1;

		// bfs 이동 큐
		queue<pair<int, int>> que;
		que.push({ y, x });

		int answer = 0;
		while (!que.empty()) {
			y = que.front().first;
			x = que.front().second;
			que.pop();

			// 도착 지점에 도달한 경우 탐색 종료
			if (maze[y][x] == 3) {
				answer = 1;
				break;
			}

			maze[y][x] = 1;
			for (int j = 0; j < dx.size(); j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				// 다음 방향 정보 큐에 추가 및 방문처리
				if (nx >= 0 && nx < MAZE_SIZE && ny >= 0 && ny < MAZE_SIZE) {
					if (maze[ny][nx] != 1) {
						que.push({ ny, nx });
					}
				}
			}
		}

		cout << "#" << tc_num << " " << answer << endl;
	}
}