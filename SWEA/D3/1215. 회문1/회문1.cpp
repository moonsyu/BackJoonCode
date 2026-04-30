#include <iostream>
#include <vector>

#define tc 10
#define board_size 8
using namespace std;


/* 가로 행 회문 검사 */
bool row_check (vector<vector<char>>& board, int row, int start, int length) {
	for (int i = 0; i < length / 2; i++) {
		if (board[row][start + i] != board[row][start + length - 1 - i]) {
			return false;
		}
	}

	return true;
}


/* 세로 열 회문 검사 */
bool column_check (vector<vector<char>>& board, int column, int start, int length) {
	for (int i = 0; i < length / 2; i++) {
		if (board[start + i][column] != board[start + length - 1 - i][column]) {
			return false;
		}
	}
	return true;
}


int main() {

	for (int i = 0; i < tc; i++) {
		int text_size;
		cin >> text_size;

		vector<vector<char>> board(board_size, vector<char>(board_size));
		for (int j = 0; j < board_size; j++) {
			for (int k = 0; k < board_size; k++) {
				cin >> board[j][k];
			}
		}

		bool palindrome_check;
		int answer = 0;
		for (int j = 0; j < board_size; j++) {
			for (int k = 0; k < board_size - text_size + 1; k++) {
				
				// 가로 행 회문 검사
				if (row_check(board, j, k, text_size)) {
					answer++;
				}

				// 세로 열 회문 검사
				if (column_check(board, j, k, text_size)) {
					answer++;
				}
			}
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}