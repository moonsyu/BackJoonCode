#include <iostream>

using namespace std;



/*
* i초 마다 i번의 폭탄이 터지며 그 여파로 상하좌우 1칸의 폭탄이 같이 터진다
* 모든 폭탄이 터질때 까지 걸리는 시간을 구하라
* 
* -------------------------------------------
* 1. 폭탄의 번호를 배열 순서대로 입력 받는다 int boom[1000][1000]
* 2. 폭탄 번호별 좌표 저장
* 3. 터진 폭탄은 -1로 표시한다
* 4. 폭탄이 터질때 마다 터진 폭탄의 수를 기록한다
* 5. 터진 폭탄의 수가 n * n이면 종료한다.
* 
* 
*/

struct Pair {
	int y;
	int x;
};

int n;
int boom[1000][1000];
Pair boom_fw[1000000];

int total_boom_cnt = 0;
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };


/* 상하좌우 4방향 폭탄 처리 */
void boom_four_fw(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < n && nx >= 0 && nx < n && boom[ny][nx] != -1) {
			boom[ny][nx] = -1;
			total_boom_cnt++;
		}
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> n;

	// 폭탄 번호별 좌표 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> boom[i][j];
			boom_fw[--boom[i][j]] = {i, j};
		}
	}

	// 폭탄 번호별 폭발 처리
	for (int i = 0; i < n * n; i++) {
		auto [y, x] = boom_fw[i]; // 해당 폭탄의 좌표 조회

		// 터질 수 있다면 폭발 처리
		if (boom[y][x] != -1) {
			boom[y][x] = -1;
			total_boom_cnt++;
			boom_four_fw(y, x);
		}

		// 모든 폭탄이 터졌을 경우 탐색 종료
		if (total_boom_cnt == n * n) {
			cout << i + 1 << "초\n";
			break;
		}
	}
}
