#include <iostream>

using namespace std;

int y, x;
char board[8][8];


/* 보드 초기화 */
void board_reset() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = '_';
		}
	}
}


/* 다른 색의 돌 개수 반환 */
int check_osello(int direction_y, int direction_x) {
	int cnt = 0;
	int ny = y + direction_y * (cnt + 1);
	int nx = x + direction_x * (cnt + 1);
	while(true) {
		if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8 || board[ny][nx] == '_') { // 범위를 벗어나면 0 반환
			cnt = 0;
			break;
		} else if (board[ny][nx] == board[y][x]) { // 같은 색의 돌이 나오면 cnt 반환
			break;
		}

		cnt++;
		ny += direction_y;
		nx += direction_x;
	}	

	return cnt;
}


/* 돌 변환 */
void change_osello(int direction_y, int direction_x) {
	int cnt = check_osello(direction_y, direction_x);// 다른 색의 돌 개수 탐색
	for (int i = 1; i <= cnt; i++) {
		board[y + direction_y * i][x + direction_x * i] = board[y][x];
	}
}


/* 출력 */
void output() {
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	board_reset();

	int n;
	cin >> n;

	int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		board[y][x] = i % 2 ? 'O' : '@';

		for (int j = 0; j < 8; j++) {
			change_osello(dy[j], dx[j]);
		}
	}

	output();
}
