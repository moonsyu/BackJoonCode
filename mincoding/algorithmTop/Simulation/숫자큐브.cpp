#include <iostream>

using namespace std;

int n;
int square[100][100] = { 0, };
int temp_square[100][100] = { 0, };


/* 회전시킬 부분을 temp_square에 복사 */
void update_temp_square(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			temp_square[i][j] = square[i][j];
		}
	}
}

/*
(y, x)  (y, x + 1)   (y, x + 2)  (y, x + size - 1)
(y + 1, x)  (y + 1, x + 1)  (y + 1, x + 2)  (y + 1, x + size - 1)
(y + 2, x)  (y + 2, x + 1)  (y + 2, x + 2)  (y + 2, x + size - 1)
(y + size - 1, x)  (y + size - 1, x + 1)  (y + size - 1, x + 2)  (y + size - 1, x + size - 1)



(y, x + size - 1)  (y + 1, x + size - 1)  (y + 2, x + size - 1)  (y + size - 1, x + size - 1)
(y, x + 2)  (y + 1, x + 2)  (y + 2, x + 2)  (y + size - 1, x + 2)
(y, x + 1)  (y + 1, x + 1)  (y + 2, x + 1)  (y + size - 1, x + 1)
(y, x)  (y + 1, x)  (y + 2, x)  (y + size - 1, x)

*/


/* 반시계 방향 90도 회전 */
void rotate_square(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			square[y + size - 1 - (j - x)][x + (i - y)] = temp_square[i][j];
		}
	}
}


/* 결과 출력 */
void output_square() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << square[i][j] << " ";
		}

		cout << "\n";
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);


	cin >> n;

	// 초기 square 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> square[i][j];
		}
	}

	// 명령어 개수 입력
	int q;
	cin >> q;

	// 명령어 개수 만큼 실행
	for (int i = 0; i < q; i++) {
		// 시작 좌표, 크기, 회전 횟수 입력
		int y, x, size, rotate_cnt;
		cin >> y >> x >> size >> rotate_cnt;

		// 회전 횟수 % 4 만큼 회전
		for (int j = 0; j < rotate_cnt % 4; j++) {
			update_temp_square(y, x, size);
			rotate_square(y, x, size);
		}
	}

	output_square();
}
