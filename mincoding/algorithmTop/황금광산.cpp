#include <iostream>

using namespace std;


struct Pair {
	int y, x;
};

int n, m;
int cave[100][100];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };


/* 채굴 가능한 황금 양 반환 */
int get_gold(int y, int x) {
	int gold = cave[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		gold += cave[ny][nx];
	}

	return gold;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cave[i][j];
		}
	}

	int answer = 0;
	Pair answer_fw = { -1, -1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int gold = get_gold(i, j);
			if (gold > answer) {
				answer = gold;
				answer_fw = { i, j };
			}
		}
	}
	
	cout << answer_fw.x + 1 << " " << answer_fw.y + 1 << " " << answer << "\n";
}
