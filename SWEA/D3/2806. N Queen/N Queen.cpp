#include <iostream>
#include <vector>

using namespace std;

long long answer;

vector<int> dx = { -1, -1, -1, 0, 1, 1, 1, 0 };
vector<int> dy = { -1, 0, 1, 1, 1, 0, -1, -1 };

/* Queen에 의한 보드 초기화 */
void reset(vector<vector<int>>& board, int x, int y, int value) {

	int n = board.size();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < dx.size(); j++) {
			int nx = x + dx[j] * i;
			int ny = y + dy[j] * i;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}

			board[nx][ny] += value;
		}
	}
}


void queen(vector<vector<int>>& board, int x, int y, int count) {
	int n = board.size();

	// Queen 기물 수 업데이트 및
	// Queen 개수 확인
	count++;
	if (count >= board.size()) {
		answer++;
		return;
	}

	// Queen위치 표시 및 공격 가능한 경로 업데이트
	board[x][y] = -1;
	reset(board, x, y, 1);


	// 다음 Queen이 위치할 수 있는 경로 탐색
	for (int j = 0; j < n && x + 1 < n; j++) {
		if (!board[x + 1][j]) {
			queen(board, x + 1, j, count);
		}
	}

	// Queen 제거 및 공격 경로 초기화
	board[x][y] = 0;
	reset(board, x, y, -1);
}


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		answer = 0;
		for (int j = 0; j < n; j++) {
			vector<vector<int>> board(n, vector<int>(n, 0));
			queen(board, 0, j, 0);
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}
}