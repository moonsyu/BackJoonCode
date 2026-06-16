#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_TC 10 /* 최대 테스트케이스 수 */
#define MAX_SIZE 100 /* 사다리의 최대 크기 */


/* 출발 점 저장
* (X가 큰 지점부터 탐색 시작)
*/
void input_start_info(queue<pair<pair<int, int>, pair<int, char>>>& que, vector<vector<int>>& ladder) {
	for (int j = MAX_SIZE - 1; j >= 0; j--) {
		if (ladder[0][j] == 1) {
			que.push({{ 0, j }, { j, ' ' }});
		}
	}
}


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int tc = 1; tc <= MAX_TC; tc++) {
		int t;
		cin >> t; /* 테스트케이스 번호 */

		queue<pair<pair<int, int>, pair<int, char>>> que; /* 현재 좌표 ((y, x), (start_x, direction))*/

		vector<vector<int>> ladder(MAX_SIZE, vector<int>(MAX_SIZE)); /* 사다리 정보 */
		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				cin >> ladder[i][j];
			}
		}
		
		input_start_info(que, ladder);

		int answer = -1; /* 정답 */
		while (!que.empty()) {
			int y = que.front().first.first;
			int x = que.front().first.second;
			int start_x = que.front().second.first;
			char direction = que.front().second.second;
			que.pop();

			// 끝 도달 시 반복문 탈출
			if (y == MAX_SIZE - 1) {
				answer = start_x;
				break;
			}

			// 좌표 이동
			if (x + 1 < MAX_SIZE && ladder[y][x + 1] == 1 && direction != 'L') {// 오른쪽 이동
				que.push({{ y, x + 1 }, { start_x, 'R' }});
				//cout << "push right: " << y << ", " << x + 1 << "\n";
			} else if (x - 1 >= 0 && ladder[y][x - 1] == 1 && direction != 'R') { // 왼쪽 이동
				que.push({{ y, x - 1 }, { start_x, 'L' }});
				//cout << "push left: " << y << ", " << x - 1 << "\n";
			} else { // 아래로 이동
				que.push({{ y + 1, x }, { start_x, 'D' }});
				//cout << "push down: " << y + 1 << ", " << x << "\n";
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}
