#include <iostream>

using namespace std;

int n, k;
int map[100][100];


/* 대각선 4방향 탐색 */
long long four_forward(int y, int x) {
	int dx[4] = { -1, -1, 1, 1 };
	int dy[4] = { -1, 1, 1, -1 };

	long long result = 0;
	for (int i = 1; i <= k; i++) { // k 크기만큼 4방향 탐색
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j] * i;
			int nx = x + dx[j] * i;

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			result += map[ny][nx];
		}
	}
	return result;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);


	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> k;
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, four_forward(i, j));
		}
	}

	cout << answer << "\n";
}
