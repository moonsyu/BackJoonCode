#include <iostream>
#include <vector>

using namespace std;

int white = 0;
int blue = 0;


void paper_calc(vector<vector<int>>& paper, int x, int y, int size) {
	if (size == 1) {
		if (paper[y][x]) {
			blue++;
		}
		else {
			white++;
		}

		return;
	}

	int color = paper[y][x];
	bool same_color = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[i][j] != color) {
				same_color = false;
				break;
			}
		}

		if (!same_color) {
			break;
		}
	}

	if (same_color) {
		if (paper[y][x]) {
			blue++;
		}
		else {
			white++;
		}
	} else {
		int new_size = size / 2;
		paper_calc(paper, x, y, new_size);
		paper_calc(paper, x + new_size, y, new_size);
		paper_calc(paper, x, y + new_size, new_size);
		paper_calc(paper, x + new_size, y + new_size, new_size);
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	/**
	* N * N 크기의 종이가 있다
	* 종이를 정사각형 모양으로 자를 때 
	* 하얀색으로만 이루어진 종이와 파란색으로만 이루어진 종이의 개수를 구하라
	* 
	* -- 자연어 풀이 --
	* 1. n을 입력 받는다
	* 2. n * n 크기의 vector 선언 후 값을 입력 받는다 (0: 하얀색, 1: 파란색)
	* 3. calc 함수 선언 (vector, x, y, size)
	* 4. calc 함수에서 size가 1이면 해당 색깔의 개수를 증가시킨다
	* 5. calc 함수에서 size가 1이 아니면 해당 영역의 색깔이 모두 같은지 확인한다
	* 6. 모두 같은 색깔이면 해당 색깔의 개수를 증가시킨다
	* 7. 모두 같은 색깔이 아니면 size를 2로 나눈 후 4개의 영역으로 나누어 calc 함수를 재귀적으로 호출한다
	*    ㄴ 1. (vector, x, y, size / 2)
	*    ㄴ 2. (vector, x + size / 2, y, size / 2)
	*    ㄴ 3. (vector, x, y + size / 2, size / 2)
	*	 ㄴ 4. (vector, x + size / 2, y + size / 2, size / 2)
	* 
	*/

	int n;
	cin >> n;

	vector<vector<int>> paper(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	paper_calc(paper, 0, 0, n);

	cout << white << "\n" << blue << "\n";
}