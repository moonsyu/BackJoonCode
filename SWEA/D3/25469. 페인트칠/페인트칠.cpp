#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 가로 행 방향 색칠 횟수 반환 */
int row_cnt(vector<vector<string>>& board) {

	int result = 0;
	for (int i = 0; i < board.size(); i++) {
		
		bool check = true;
		for (int j = 0; j < board[i].size() && check; j++) {
			if (board[i][j] != "#") {
				check = false;
			}
		}

		if (check) {
			result++;
		}
	}

	return result;
}


/* 세로 열 방향 색칠 횟수 반환 */
int col_cnt(vector<vector<string>>& board) {

	int result = 0;
	for (int i = 0; i < board[0].size(); i++) {

		bool check = true;
		for (int j = 0; j < board.size() && check; j++) {
			if (board[j][i] != "#") {
				check = false;
			}
		}

		if (check) {
			result++;
		}
	}

	return result;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int h, w;
		cin >> h >> w;

		vector<vector<string>> board(h, vector<string>(w));
		for (int i = 0; i < h; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < w; j++) {
				board[i][j] = input[j];
			}
		}

		// 가로 세로 방향으로 칠한 횟수 세기
		int answer = 0;
		answer += row_cnt(board);
		answer += col_cnt(board);

		// 만약 모든 칸이 칠해져 있다면
		if (answer == h + w) {
			// 더 작은 방향으로 갱신
			answer = min(h, w);
		}

		cout << answer << endl;
	}
}