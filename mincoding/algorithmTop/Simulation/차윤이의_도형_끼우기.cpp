#include <iostream>
#include <set>

#define circle_size 4
#define board_size 10

using namespace std;

/*
* 입력 받은 도형을 활용하여 빈칸에 채울 수 있는 경우의 수 계산
* 
* 
* 1. 도형의 모양을 입력 받는다.
* 3. 도형을 0, 90, 180, 270도 회전한 모양의 좌표를 저장한다.
* 4. 검은 판의 모든 좌표를 대상으로 도형을 넣을 수 있는지 확인한다.
*    ㄴ 현재 좌표를 기준으로 도형의 좌표를 더한 위치가 모두 배치 가능하면 true
* 
* 
*/

/* 도형의 좌표 */
struct Pair {
	int y, x;
};

/* 도형의 좌표 배열 */
struct Circle_data {
	Pair p[16];
	int cnt = 0;

	bool operator<(const Circle_data& other) const {
		if (cnt != other.cnt) return cnt < other.cnt;

		for (int i = 0; i < cnt; i++) {
			if (p[i].y != other.p[i].y) return p[i].y < other.p[i].y;
			if (p[i].x != other.p[i].x) return p[i].x < other.p[i].x;
		}
		return false; // 모든 좌표가 같으면 동일한 데이터로 취급
	}
};

// y, x, 회전 축 (0: 0도, 1: 90도, 2: 180도, 3: 270도)
char circle[circle_size][circle_size][4];
char board[board_size][board_size];

set<Circle_data> circles;


/* 도형의 시작 좌표 찾기 */
Pair find_start_fw(int direction) {
	Pair result = {0, 0};
	for (int i = 0; i < circle_size; i++) {
		for (int j = 0; j < circle_size; j++) {
			if (circle[i][j][direction] == '$') {
				result = { i, j };
				return result;
			}
		}
	}

	return result;
}

int front, rear;
Pair que[16];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

/* 도형의 좌표를 set에 추가 */
void circle_to_set(int direction) {
	Circle_data cd;

	front = rear = 0;
	que[rear++] = find_start_fw(direction);

	auto [y, x] = que[0];
	circle[y][x][direction] = '_'; // 방문 처리
	while (front < rear) {
		Pair now = que[front++];
		cd.p[cd.cnt++] = {now.y - y, now.x - x};
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			// 범위를 벗어나거나, 도형이 아닌 경우 continue
			if (ny < 0 || nx < 0 || ny >= circle_size || nx >= circle_size) {
				continue;
			} else if (circle[ny][nx][direction] == '_') {
				continue;
			}

			que[rear++] = { ny, nx }; // 도형 좌표를 큐에 추가
			circle[ny][nx][direction] = '_'; // 방문 처리
		}
	}
	
	circles.insert(cd);
}


/* 도형 회전 */
void rotate(int direction) {
	char temp[circle_size][circle_size];
	for (int i = 0; i < circle_size; i++) {
		for (int j = 0; j < circle_size; j++) {
			temp[circle_size - 1 - j][i] = circle[i][j][direction];
		}
	}

	for (int i = 0; i < circle_size; i++) {
		for (int j = 0; j < circle_size; j++) {
			circle[i][j][direction + 1] = temp[i][j];
		}
	}
}


/* 가짓 수 찾기 */
int find_case() {
	int answer = 0;
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			if (board[i][j] == '_') {
				for (auto& cd : circles) {
					bool is_possible = true;
					for (int k = 0; k < cd.cnt; k++) {
						int ny = i + cd.p[k].y;
						int nx = j + cd.p[k].x;

						// 범위를 벗어나거나, 빈칸이 아닌 경우 continue
						if (ny < 0 || nx < 0 || ny >= board_size || nx >= board_size || board[ny][nx] == '#') {
							is_possible = false;
							break;
						}
					}

					if (is_possible) {
						answer++;
					}
				}
			}
		}
	}

	return answer;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	circles.clear();
	// 도형 정보 입력
	for (int i = 0; i < circle_size; i++) {
		for (int j = 0; j < circle_size; j++) {
			cin >> circle[i][j][0];
		}
	}

	// 도형 회전
	for (int i = 0; i < 3; i++) {
		rotate(i);
	}

	// 도형 좌표를 set에 추가
	for (int i = 0; i < 4; i++) {
		circle_to_set(i);
	}

	// 보드 정보 입력
	for (int i = 0; i < board_size; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < board_size; j++) {
			board[i][j] = input[j];
		}
	}

	cout << find_case() << "\n";
}
