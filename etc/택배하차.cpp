#include <iostream>

using namespace std;

/*
 * 택배 정보를 입력받아 공간 안에 적재한 후,
 * 좌측과 우측을 번갈아 가며 한 개씩 택배를 제거하는 문제
 * 택배를 제거할 때마다 해당 택배 번호를 출력한다.
 *
 * -- 조건 --
 * 1. 좌측, 우측 번갈아 가며 택배를 제거한다.
 * 2. 택배 제거 시 각 방향에 다른 택배가 없어야 한다.
 * 3. 택배 제거 시 남은 택배가 비어 있는 공간으로 떨어져야 한다.
 *
 * -- 풀이 --
 * 1. 각 택배 번호를 인덱스로 사용하여 위치, 크기, 존재 여부를 저장한다.
 * 2. 2차원 bool 배열을 이용해 각 격자 칸에 택배가 존재하는지 표시한다.
 * 3. 각 열에서 다음 택배가 놓일 수 있는 높이를 1차원 배열에 저장한다.
 * 4. 입력된 택배는 차례대로 현재 각 열의 높이를 확인하여 떨어뜨린다.
 * 5. 좌측 차례에는 택배의 왼쪽 경로를, 우측 차례에는 오른쪽 경로를 확인한다.
 * 6. 현재 방향으로 제거할 수 있는 택배를 번호가 작은 순서대로 탐색한다.
 * 7. 선택한 택배를 공간에서 제거하고 택배 번호를 출력한다.
 * 8. 남은 택배로 다시 재배치한다.
 * 9. 5~8번 과정을 m번 반복한다.
 * 
 */

struct Box_info {
    int y, x;
    int h, w;
    bool is_exist;
};

Box_info box_fw[101];      // 택배 번호별 위치 및 크기 정보
bool check[51][51];    // 각 격자 칸의 택배 존재 여부
int y_height[51];      // 각 열에서 택배를 놓을 수 있는 높이
int box_order[101];    // 택배 번호별 입력 순서

int n, m, max_k;


/* 각 열의 높이 초기화 */
void reset_y_height() {
    for (int i = 0; i < n; i++) {
        y_height[i] = n;
    }
}


/* 격자와 각 열의 높이 초기화 */
void reset_space() {
	fill(&check[0][0], &check[50][51], false);

    reset_y_height();
}


/* 택배를 놓을 수 있는 y 좌표 계산 */
int calc_y_height(int x, int h, int w) {
    int min_y = n;
    for (int i = x; i < x + w; i++) {
        min_y = min(min_y, y_height[i]);
    }

    // 택배가 차지한 모든 열의 높이를 갱신
    for (int i = x; i < x + w; i++) {
        y_height[i] = min_y - h;
    }

    return min_y - h;
}


/* 저장된 택배를 현재 공간에 떨어뜨려 배치 */
void place_box(int k) {
    auto [y, x, h, w, is_exist] = box_fw[k];
    box_fw[k].y = y = calc_y_height(x, h, w);

    // 택배가 차지하는 공간 표시
    for (int i = y; i < y + h; i++) {
        for (int j = x; j < x + w; j++) {
            check[i][j] = true;
        }
    }
}


/* 새로운 택배 정보 저장 및 배치 */
void update_box_fw(int k, int x, int h, int w) {
    box_fw[k] = { 0, x, h, w, true };
    place_box(k);
}


/* 택배 정보 입력 */
void input() {
    int k, h, w, c;

    for (int i = 0; i < m; i++) {
        cin >> k >> h >> w >> c;
        box_order[i] = k;

        max_k = max(max_k, k);
        update_box_fw(k, c - 1, h, w);
    }
}


/* 좌측으로 택배를 제거할 수 있는지 확인 */
bool remove_left_box(int k) {
    auto [y, x, h, w, is_exist] = box_fw[k];

    for (int i = y; i < y + h; i++) {
        for (int j = 0; j < x; j++) {
            if (check[i][j]) {
                return false;
            }
        }
    }

    cout << k << "\n";
    return !(box_fw[k].is_exist = false);
}


/* 우측으로 택배를 제거할 수 있는지 확인 */
bool remove_right_box(int k) {
    auto [y, x, h, w, is_exist] = box_fw[k];

    for (int i = y; i < y + h; i++) {
        for (int j = x + w; j < n; j++) {
            if (check[i][j]) {
                return false;
            }
        }
    }

	cout << k << "\n";
    return !(box_fw[k].is_exist = false);
}


/* 택배 하차 로직 */
void answer() {
    for (int turn = 0; turn < m; turn++) {
        // 제거 완료 시 탐색 종료
        bool can_remove = false;
        for (int k = 1; k <= max_k && !can_remove; k++) {
			// 박스 존재 시 turn에 따라 좌측 또는 우측 제거 시도
            if (box_fw[k].is_exist) {
                can_remove = (turn % 2 ? remove_right_box(k) : remove_left_box(k));
            }
        }

        // 택배 공간 초기화
        reset_space();

        // 택배 재배치
        for (int i = 0; i < m; i++) {
            int box_idx = box_order[i];
            if (box_fw[box_idx].is_exist) {
                place_box(box_idx);
            }
        }
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    max_k = 0;
    cin >> n >> m;
    
    reset_space();
    input();
    answer();
}
