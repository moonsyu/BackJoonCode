#include <iostream>

using namespace std;

/*
* 1. 처음 찾은 색인지 기록할 배열 생성
* 2. 색의 시작과 끝 좌표를 기록할 배열 생성
* 3. 0이 아닌 색을 찾았을 때, 처음 찾은 색 인지 확인
* 4. 처음 찾은 색이라면 해당 위치부터 전탐 시작
*    ㄴ 전탐 시 y와 x의 각 최소, 최대 값 기록
* 5. 이후 1 ~ 9까지 있었던 색 탐색
* 6. 있었던 색의 범위 내에 다른 숫자가 있다면
* 7. 해당 색은 처음이 불가능 하므로 false 처리
* 8. 동일한 로직으로 모든 숫자 탐색 후
* 9. 배열 내 true인 색의 개수 출력
* 
* 
* 
*/

// 색의 시작과 끝 좌표를 기록할 구조체
struct Coor {
	int start_y = 10, start_x = 10;
	int end_y = -1, end_x = -1;
};

int n;
int canvas[10][10];


// 색의 시작과 끝 좌표를 기록할 구조체 배열
Coor color_coor[10];

// 사용 및 초기 색 여부를 기록할 배열
bool answer_color[10];


/* 가능한 사각형의 좌표 기록 */
void log_cool(int color) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int now_color = canvas[i][j];
			
			if (now_color == color) {
				color_coor[color].start_y = min(color_coor[color].start_y, i);
				color_coor[color].start_x = min(color_coor[color].start_x, j);
				color_coor[color].end_y = max(color_coor[color].end_y, i);
				color_coor[color].end_x = max(color_coor[color].end_x, j);
			}
		}
	}
}


/* 초기 색 가능 여부 확인 */
void first_color_possible() {
	for (int color = 1; color <= 9; color++) {
		auto [start_y, start_x, end_y, end_x] = color_coor[color];
		for (int i = start_y; i <= end_y; i++) {
			for (int j = start_x; j <= end_x; j++) {
				int now_color = canvas[i][j];
				if (now_color && now_color != color) {
					answer_color[now_color] = false;
				}
			}
		}
	}
}


/* 정답 반환 */
int output() {
	int answer = 0;
	for (int color = 1; color <= 9; color++) {
		if (answer_color[color]) {
			answer++;
		}
	}

	return answer;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < n; j++) {
			canvas[i][j] = input[j] - '0';
		}
	}

	// 색 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int color = canvas[i][j];
			
			// 처음 찾은 색일 경우
			if (color && !answer_color[color]) {
				answer_color[color] = true;
				log_cool(color);
			}
		}
	}

	// 초기 색 가능 여부 확인
	first_color_possible();

	cout << output() << "\n";
}
