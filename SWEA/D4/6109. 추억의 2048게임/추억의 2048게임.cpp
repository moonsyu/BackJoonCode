#include <iostream>
#include <deque>

using namespace std;

int n; // 배열 크기
string fw; // 방향
int tile[20][20]; // 타일

deque<pair<int, bool>> stack; // 블록을 담을 스택

/* 위로 이동 */
void up() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (!tile[y][x]) { // 0값 버림
				continue;
			}

			if (!stack.empty()) {
				if (stack.back().first == tile[y][x] && stack.back().second) {
					stack.pop_back();
					stack.push_back({ tile[y][x] * 2, false });
				} else {
					stack.push_back({ tile[y][x], true });
				}
			} else {
				stack.push_back({ tile[y][x], true });
			}
		}

		for (int y = 0; y < n; y++) {
			if (stack.empty()) {
				tile[y][x] = 0;
			} else {
				tile[y][x] = stack.front().first;
				stack.pop_front();
			}
		}
	}
}


/* 아래로 이동 */
void down() {
	for (int x = 0; x < n; x++) {
		for (int y = n - 1; y >= 0; y--) {
			if (!tile[y][x]) { // 0값 버림
				continue;
			}

			if (!stack.empty()) {
				if (stack.back().first == tile[y][x] && stack.back().second) {
					stack.pop_back();
					stack.push_back({ tile[y][x] * 2, false });
				}
				else {
					stack.push_back({ tile[y][x], true });
				}
			}
			else {
				stack.push_back({ tile[y][x], true });
			}
		}

		for (int y = n - 1; y >= 0; y--) {
			if (stack.empty()) {
				tile[y][x] = 0;
			}
			else {
				tile[y][x] = stack.front().first;
				stack.pop_front();
			}
		}
	}
}


/* 왼쪽으로 이동 */
void left() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (!tile[y][x]) { // 0값 버림
				continue;
			}

			if (!stack.empty()) {
				if (stack.back().first == tile[y][x] && stack.back().second) {
					stack.pop_back();
					stack.push_back({ tile[y][x] * 2, false });
				}
				else {
					stack.push_back({ tile[y][x], true });
				}
			}
			else {
				stack.push_back({ tile[y][x], true });
			}
		}

		for (int x = 0; x < n; x++) {
			if (stack.empty()) {
				tile[y][x] = 0;
			}
			else {
				tile[y][x] = stack.front().first;
				stack.pop_front();
			}
		}
	}
}


/* 오른쪽으로 이동 */
void right() {
	for (int y = 0; y < n; y++) {
		for (int x = n - 1; x >= 0; x--) {
			if (!tile[y][x]) { // 0값 버림
				continue;
			}

			if (!stack.empty()) {
				if (stack.back().first == tile[y][x] && stack.back().second) {
					stack.pop_back();
					stack.push_back({ tile[y][x] * 2, false });
				}
				else {
					stack.push_back({ tile[y][x], true });
				}
			}
			else {
				stack.push_back({ tile[y][x], true });
			}
		}

		for (int x = n - 1; x >= 0; x--) {
			if (stack.empty()) {
				tile[y][x] = 0;
			}
			else {
				tile[y][x] = stack.front().first;
				stack.pop_front();
			}
		}
	}
}


/* 최종 출력 */
void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tile[i][j] << " ";
		}

		cout << endl;
	}
}


int main() {

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n >> fw;

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				cin >> tile[i][j];


		// 명령어에 따른 블록 이동 처리
		if (fw == "up") up();
		if (fw == "down") down();
		if (fw == "left") left();
		if (fw == "right") right();

		// 결과 출력
		cout << "#" << t << endl;
		output();
	}
}