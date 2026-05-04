#include <iostream>
#include <vector>
#include <set>

#define board_size 4
#define num_size 7

using namespace std;

set<int> num_set;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

/* 조합의 경우의 수 조회 */
void combination(vector<vector<int>>& board, int x, int y, int num, int cnt) {
	
	if (cnt == num_size) {
		num_set.insert(num);
		return;
	} else {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < board_size && ny >= 0 && ny < board_size) {
				int new_num = num * 10 + board[nx][ny];
				combination(board, nx, ny, new_num, cnt + 1);
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		vector<vector<int>> board(board_size, vector<int>(board_size));
		for (int j = 0; j < board_size; j++) {
			for (int k = 0; k < board_size; k++) {
				cin >> board[j][k];
			}
		}

		num_set.clear();
		for (int j = 0; j < board_size; j++) {
			for (int k = 0; k < board_size; k++) {
				combination(board, j, k, board[j][k], 1);
			}
		}

		cout << "#" << i + 1 << " " << num_set.size() << endl;
	}
}