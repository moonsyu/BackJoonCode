#include <iostream>

using namespace std;

/*
* y1, x1 좌표 y2, x2 를 입력 받는다
* 해당 좌표를 이용하여 min(y1, y2) ~ max(y1, y2) 범위와 min(x1, x2) ~ max(x1, x2) 범위를 이용하여 사각형을 그린다
* 이때 기존 값보다 클 경우에만 값을 갱신한다
* 
* 
* 이후 0,0 부터 탐색을 시작하며 1 이상인 값을 찾는다
* 해당 좌표 기준으로 1, 2, 3씩 길이를 늘려가며 정사각형인지 탐색한다
* 정사각형의 최대 길이를 갱신한다
* 
* 이후 정사각형의 최대 길이 부터 1씩 늘려가며 더 큰 정사각형을 탐색한다
* 
* 정사각형의 최대 길이 ^ 2을 출력한다.
* 
*/

int n;
int canvas[10][10];


void find_square(int y, int x, int& size) {
	if (canvas[y][x] == 0) return;

	int color = canvas[y][x];
	bool is_square = true;
	while (is_square) {
		size++;
		for (int i = y; i < y + size && is_square; i++) {
			for (int j = x; j < x + size && is_square; j++) {
				if (i >= n || j >= n || canvas[i][j] != color) {
					is_square = false;
				}
			}
		}
	}

	size--;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	
	cin >> n;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int color, y1, x1, y2, x2;
		cin >> color >> y1 >> x1 >> y2 >> x2;
		for (int y = min(y1, y2); y <= max(y1, y2); y++) {
			for (int x = min(x1, x2); x <= max(x1, x2); x++) {
				canvas[y][x] = max(canvas[y][x], color);
			}
		}
	}

	int max_square_size = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			canvas[i][j] ? find_square(i, j, max_square_size) : void();
		}
	}
	


	cout << max_square_size * max_square_size << "\n";
}
