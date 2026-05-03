#include <iostream>
#include <vector>

using namespace std;

// 좌측부터 시계방향으로 8방향
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };


/* 오셀로 돌 색 변경 */
void change_color(vector<vector<int>>& board, vector<pair<int, int>>& stack, int color) {
	for (pair<int, int> pii : stack) {
		board[pii.first][pii.second] = color;
	}
}


/* 오셀로 탐색 */
void board_search(vector<vector<int>>& board) {

	// 좌표와 돌 색 입력
	int x, y, color;
	cin >> x >> y >> color;

	x -= 1;
	y -= 1;

	board[x][y] = color;

	vector<pair<int, int>>  stack;
	for (int i = 0; i < 8; i++) {
		//for (vector<int> y : board) {
		//	for (int cell : y) {
		//		cout << cell << " |";
		//	}
		//	cout << "\n-----------------\n";
		//}
		//cout << "\n";


		// 한쪽 방향의 끝까지 탐색
		for (int j = 1; j < board.size(); j++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			// 범위를 벗어나면 탐색 종료
			if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
				break;
			}

			// 다음 위치에 돌이 있을때
			if (board[nx][ny]) {
				// 현재 돌과 다른 색의 돌이 있으면 
				// 스택에 좌표 추가
				if (board[nx][ny] != color) {
					stack.push_back({ nx, ny });
				}
				// 같은 색이라면 스택에 있는 좌표의 돌 색 변경 후 탐색 종료
				else {
					change_color(board, stack, color);
					break;
				}
			}
			// 다음 위치에 돌이 없다면 탐색 종료
			else {
				break;
			}
		}

		stack.clear();
	}
}


/* 보드에 있는 돌 개수 조회 */
pair<int, int> rock_cnt(vector<vector<int>>& board) {
	int black = 0, white = 0;
	for (vector<int> row : board) {
		for (int cell : row) {
			if (cell == 1) {
				black++;
			}
			else if (cell == 2) {
				white++;
			}
		}
	}
	return { black, white };
}


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> board(n, vector<int>(n));
		
		// 중앙에 흑돌과 백돌 세팅
		int center = n / 2;
		board[center - 1][center - 1] = 2;
		board[center - 1][center] = 1;
		board[center][center - 1] = 1;
		board[center][center] = 2;

		for (int j = 0; j < m; j++) {
			board_search(board);
		}

		pair<int, int> answer = rock_cnt(board);

		cout << "#" << i + 1 << " " << answer.first << " " << answer.second << "\n";
	}

}