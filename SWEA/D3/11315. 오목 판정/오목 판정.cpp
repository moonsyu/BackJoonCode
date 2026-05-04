#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

/* 오목 판정 함수 */
bool find_omok(vector<vector<string>>& board, pair<int, int> location) {
	bool result = false;
	
	int x = location.first;
	int y = location.second;

	for (int i = 0; i < 8; i++) {

		int rock_cnt = 0;
		for (int j = 0; j < 5; j++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			// 배열 범위 확인
			if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
				break;
			}

			// 오목 확인
			if (board[nx][ny] == "o") {
				rock_cnt++;
			} else {
				break;
			}
		}

		if (rock_cnt == 5) {
			result = true;
			break;
		}
	}

	return result;
}


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		vector<pair<int, int>> rock_loctions;

		vector<vector<string>> board(n, vector<string>(n));
		for (int j = 0; j < n; j++) {
			string text;
			cin >> text; 

			for (int k = 0; k < n; k++) {
				board[j][k] = text[k];
				if (text[k] == 'o') {
					rock_loctions.push_back({ j, k });
				}
			}
		}

		bool result = false;
		for (int j = 0; j < rock_loctions.size(); j++) {
			result = find_omok(board, rock_loctions[j]);
			
			 if (result) {
				break;
			}
		}

		if (result) {
			cout << "#" << i + 1 << " YES" << endl;
		} else {
			cout << "#" << i + 1 << " NO" << endl;
		}
	}
}