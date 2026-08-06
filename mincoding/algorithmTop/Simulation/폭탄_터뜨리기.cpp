#include <iostream>

using namespace std;

struct Pair {
	int y, x;
};

int n, m, k;
char map[20][20];
int stack_idx;
Pair stack[400];


/* 4방향 탐색 */
void four_forward(int y, int x) {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };

	for (int i = 1; i <= k; i++) { // k 크기만큼 4방향 탐색
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j] * i;
			int nx = x + dx[j] * i;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (map[ny][nx] == '_' || map[ny][nx] == '%') { // 빈 공간이면 %로 바꾸기
				map[ny][nx] = '%';
			} else { // 벽이면 해당 방향 탐색 종료
				dy[j] = dx[j] = 0;
			}
		}
	}
}


/* 출력 */
void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);


	cin >> n >> m >> k;
	stack_idx = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			cin >> map[i][j];
			stack[stack_idx++] = {i, j};
		}
	}

	for (int i = 0; i < stack_idx; i++) {
		auto [y, x] = stack[i];
		if (map[y][x] == '@') {
			map[y][x] = '%';
			four_forward(y, x);
		}
	}

	output();
}
