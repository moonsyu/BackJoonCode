#include <iostream>

using namespace std;

/*
* 미생물이 이동하며 M 시간 후 살아남은 미생물 수 출력 문제
* 
* --- 조건 ---
* 1. 미생물은 1시간에 1칸 이동 (방향 주어짐)
* 2. 벽에 닿을 경우 수 / 2, 반대로 방향 전환
* 3. 같은 칸에 여러 미생물이 모이면 합쳐짐
* 
* 
* --- 풀이 ---
* 1. 각 칸에 도착한 현재 미생물 수, 최대 군집 미생물 수, 방향 기록 구조체 생성
* 2. 1.에서 생성한 구조체로 2차원 배열 생성
* 3. 미생물의 현재 정보 입력 및 구조체 배열에 저장
* 4. 이동 후 각 칸에 도착한 미생물 수, 최대 군집 미생물 수, 방향 기록할 2차원 배열 생성
* 5. 매 M 시간마다 배열을 확인하며 위치 업데이트
* 6. 마지막 배열 확인 후 살아남은 미생물 수 출력
* 
* 
*/

struct Microbe {
	int count; // 미생물 수
	int max_count; // 최대 군집 미생물 수
	int direction; // 방향 (1: 상, 2: 하, 3: 좌, 4: 우)
	int time; // 이동 시간
};

Microbe grid1[100][100]; // 미생물 정보 저장 2차원 배열
Microbe grid2[100][100]; // 이동 후 미생물 정보 저장 2차원 배열

int n, m, k; // n: 격자 크기, m: 이동 시간, k: 미생물 군집 수


/* 그리드 초기화 */
void reset_grid() {
	fill(grid1[0], grid1[0] + 100 * 100, Microbe{ 0, 0, 0, 0 });
	fill(grid2[0], grid2[0] + 100 * 100, Microbe{ 0, 0, 0, 0 });
}


/* 미생물 정보 입력 */
void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		cin >> grid1[y][x].count >> grid1[y][x].direction;
	}
}


/* 미생물 정보 업데이트 */
void update_grid(Microbe now_grid[][100], Microbe next_grid[][100], Microbe& info, int mv_y, int mv_x) {
	auto [count, max_count, direction, time] = info;
	if (next_grid[mv_y][mv_x].time > time) {
		next_grid[mv_y][mv_x].count += count;

		if (next_grid[mv_y][mv_x].max_count < count) {
			next_grid[mv_y][mv_x].max_count = count;
			next_grid[mv_y][mv_x].direction = direction;
		}
	} else {
		next_grid[mv_y][mv_x] = { count, count, direction, time + 1 };
	}
}


/* 경계에 닿은 미생물 처리 */
void border_microbe(Microbe& now_grid) {
	now_grid.count /= 2;
	if (now_grid.direction == 1) {
		now_grid.direction = 2;
	} else if (now_grid.direction == 2) {
		now_grid.direction = 1;
	} else if (now_grid.direction == 3) {
		now_grid.direction = 4;
	} else if (now_grid.direction == 4) {
		now_grid.direction = 3;
	}
}


/* 미생물 이동 로직 */
void mv_microbe(Microbe now_grid[][100], Microbe next_grid[][100], int time) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (now_grid[i][j].count > 0 && now_grid[i][j].time == time) {
				// 경계에 닿은 미생물 처리
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
					border_microbe(now_grid[i][j]);
				}

				// 방향에 따라 미생물 이동 
				int direction = now_grid[i][j].direction;
				if (direction == 1) {
					update_grid(now_grid, next_grid, now_grid[i][j], i - 1, j);
				} else if (direction == 2) {
					update_grid(now_grid, next_grid, now_grid[i][j], i + 1, j);
				} else if (direction == 3) {
					update_grid(now_grid, next_grid, now_grid[i][j], i, j - 1);
				} else if (direction == 4) {
					update_grid(now_grid, next_grid, now_grid[i][j], i, j + 1);
				}
			}
		}
	}
}


/* 미생물 이동 시작 */
void move() {
	// 시간에 따른 미생물 배열 선택
	for (int time = 0; time < m; time++) {
		if (time % 2) {
			mv_microbe(grid2, grid1, time);
		} else {
			mv_microbe(grid1, grid2, time);
		}
	}
}


/* 살아남은 미생물 수 계산 */
long long output(Microbe result_grid[][100]) {
	long long result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (result_grid[i][j].count > 0 && result_grid[i][j].time == m) {
				// 경계에 닿은 미생물 처리
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
					border_microbe(result_grid[i][j]);
				}

				result += result_grid[i][j].count;
			}
		}
	}

	return result;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		reset_grid(); // 그리드 초기화
		input(); // 미생물 정보 입력
		move(); // 미생물 이동 시작

		long long result = output((m % 2) ? grid2 : grid1); // 살아남은 미생물 수 계산
		cout << "#" << t << " " << result << "\n";
	}
}