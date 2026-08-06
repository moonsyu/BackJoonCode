#include <iostream>
#include <string>

using namespace std;

/*
* 출발 좌표와 방향을 입력 받는다
* 출발 좌표는 (5, 입력 좌표)
* L 방향 시 (1, -1)을 지속적으로 더해준다
* 만일 x == 0이 되면 (1, 1)로 변경
* y == 0이되면 (-1, -1)로 변경
* 
* 이러한 규칙을 기반으로 각 방향에 따른 팅김 좌표 변환 규칙은 다음과 같다
* x == 0 || x == 5일 때, y 방향은 두고 x 방향만 반대로 바꾼다
* y == 0 || y == 5일 때, x 방향은 두고 y 방향만 반대로 바꾼다
* 
* 이때 visit 배열을 사용하며, 같은 차례의 중복 방문 시 멈춘다
* 
*/

struct Pair {
	int y, x;
};


int n;
int canvas[6][6];
bool visited[6][6];


/* 방문 배열 초기화 */
void reset_visited() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = true;
		}
	}
}


/* 출력하기 */
void output() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << (canvas[i][j] ? to_string(canvas[i][j]) : "_");
		}
		cout << '\n';
	}
}


/* 색칠하기 */
void drawing_color(int y, int x, Pair direction) {
	
	int log_num = 1;
	while (visited[y][x]) {
		visited[y][x] = false;
		if (canvas[y][x]) {
			canvas[y][x] = min(canvas[y][x], log_num++);
		} else {
			canvas[y][x] = log_num++;
		}

		int ny = y + direction.y;
		int nx = x + direction.x;

		if (ny < 0 || ny > 5) {
			direction.y *= -1;
			ny = y + direction.y;
		}

		if (nx < 0 || nx > 5) {
			direction.x *= -1;
			nx = x + direction.x;
		}

		y = ny;
		x = nx;
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int start_x;
		char direction;
		cin >> start_x >> direction;

		
		reset_visited();
		drawing_color(5, start_x, (direction == 'R' ? Pair{-1, 1} : Pair{-1, -1}));
	}
	
	output();
}
