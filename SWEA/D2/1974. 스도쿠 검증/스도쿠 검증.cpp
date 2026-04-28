#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SQUARE_SIZE 9

bool check;

/** 행 체크 */
void check_row(const vector<vector<int>>& board) {

	for (int i = 0; i < SQUARE_SIZE && check; i++) {
		vector<int> now_row = board[i];

		sort(now_row.begin(), now_row.end());
		for (int j = 0; j < SQUARE_SIZE - 1 && check; j++) {
			if (now_row[j] == now_row[j + 1]) {
				check = false;
			}
		}
	}
}

/** 열 체크 */
void check_column(const vector<vector<int>>& board) {

	for (int i = 0; i < SQUARE_SIZE && check; i++) {
		vector<int> now_col;
		for (int j = 0; j < SQUARE_SIZE && check; j++) {
			now_col.push_back(board[j][i]);
		}

		sort(now_col.begin(), now_col.end());
		for (int j = 0; j < SQUARE_SIZE - 1 && check; j++) {
			if (now_col[j] == now_col[j + 1]) {
				check = false;
			}
		}
	}
}

/** 사각형 체크 */
void check_square(const vector<vector<int>>& board) {
	
	for (int i = 0; i < SQUARE_SIZE && check; i += 3) {
		for (int j = 0; j < SQUARE_SIZE && check; j += 3) {
			vector<int> now_square;
			for (int start_col = i; start_col < i + 3; start_col++) {
				for (int start_raw = j; start_raw < j + 3; start_raw++) {
					now_square.push_back(board[start_col][start_raw]);
				}
			}

			sort(now_square.begin(), now_square.end());
			for (int k = 0; k < SQUARE_SIZE - 1 && check; k++) {
				if (now_square[k] == now_square[k + 1]) {
					check = false;
				}
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;

	vector<vector<int>> board(SQUARE_SIZE, vector<int>(SQUARE_SIZE));
	for (int i = 0; i < tc; i++) {
		for (int j = 0; j < SQUARE_SIZE; j++) {
			for (int k = 0; k < SQUARE_SIZE; k++) {
				cin >> board[j][k];
			}
		}

		check = true;
		check_row(board);
		check_column(board);
		check_square(board);

		cout << "#" << i + 1 << " " << (check ? "1" : "0") << endl;

	}
}