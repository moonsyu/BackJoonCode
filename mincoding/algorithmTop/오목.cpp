#include <iostream>
#include <string>

#define MAX_SIZE 19

using namespace std;


/*
* 같은 색의 알이 5개 연속으로 놓이면 해당 색이 이기는 프로그램
* 
* 0,0 ~ 19, 19까지 순차적으로 탐색
* 우측, 우하단, 하단, 우상단 방향만 탐색
* 
* 바둑알 색 기록 및 해당 y, x 좌표부터 각각의 방향으로 5칸씩 확인
* 만약 5칸이 모두 같은 색이라면, 6칸 째 확인
* 6칸 째가 다른 색이라면 해당 돌이 이긴것으로 판단
*/


int board[MAX_SIZE][MAX_SIZE];


/* 동일 방향에 같은 돌이 있는지 확인 */
bool add_color_check(int y, int x, int dy, int dx, int color) {
	int ny = y + dy * 5;
	int nx = x + dx * 5;

	// 바둑판 범위를 벗어날경우 성공
	if (ny < 0 || ny >= MAX_SIZE || nx < 0 || nx >= MAX_SIZE) {
		return true;
	} else if (board[ny][nx] != color) { // 다른 색의 돌이 놓여있을 경우 성공
		return true;
	}
	
	return false;
}


/* 반대 방향에 같은 돌이 있는지 확인 */
bool reverse_color_check(int y, int x, int dy, int dx, int color) {
	int ny = y + dy * -1;
	int nx = x + dx * -1;

	// 바둑판 범위를 벗어날경우 성공
	if (ny < 0 || ny >= MAX_SIZE || nx < 0 || nx >= MAX_SIZE) {
		return true;
	} else if (board[ny][nx] != color) { // 다른 색의 돌이 놓여있을 경우 성공
		return true;
	}

	return false;
}


/* 승리 여부 확인 */
int dx[] = { 1, 1, 0, 1 };
int dy[] = { 0, 1, 1, -1 };
bool win_check(int y, int x) {
	int color = board[y][x];

	for (int i = 0; i < 4; i++) { // 4방향
		bool is_same = true;
		for (int j = 0; j < 5 && is_same; j++) { // 5칸 확인
			int ny = y + dy[i] * j;
			int nx = x + dx[i] * j;

			if (ny < 0 || ny >= MAX_SIZE || nx < 0 || nx >= MAX_SIZE) { // 바둑판 범위를 벗어날경우 실패
				is_same = false;
			} else if (board[ny][nx] != color) { // 다른 색의 돌이 놓여있을 경우 실패
				is_same = false;
			}
		}

		// 육목 이상인지 확인
		if (is_same && add_color_check(y, x, dy[i], dx[i], color) && reverse_color_check(y, x, dy[i], dx[i], color)) {
			return true;
		}
	}

	return false;
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (!board[i][j]) { // 돌이 없는 경우 패스
				continue;
			}

			// 해당 좌표에서 승리 조건 확인
			if (win_check(i, j)) {
				cout << board[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
		}
	}

	cout << 0;
}
