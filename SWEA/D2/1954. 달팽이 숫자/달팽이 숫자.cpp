#include <iostream>
#include <vector>

using namespace std;

string fw = "";

void dfs(vector<vector<int>>& square, int x, int y, int num) {
	
	square[y][x] = num;
	if (fw == "right") {
		if (x + 1 < square.size() && !square[y][x + 1]) {
			dfs(square, x + 1, y, num + 1);
		} else if(y + 1 < square.size() && !square[y + 1][x]){
			fw = "down";
			dfs(square, x, y + 1, num + 1);
		}
	} else if (fw == "down") {
		if (y + 1 < square.size() && !square[y + 1][x]) {
			dfs(square, x, y + 1, num + 1);
		}
		else if (x - 1 >= 0 && !square[y][x - 1]) {
			fw = "left";
			dfs(square, x - 1, y, num + 1);
		}
	} else if (fw == "left") {
		if (x - 1 >= 0 && !square[y][x - 1]) {
			dfs(square, x - 1, y, num + 1);
		}
		else if (y - 1 >= 0 && !square[y - 1][x]) {
			fw = "up";
			dfs(square, x, y - 1, num + 1);
		}
	} else if (fw == "up") {
		if (y - 1 >= 0 && !square[y - 1][x]) {
			dfs(square, x, y - 1, num + 1);
		}
		else if (x + 1 < square.size() && !square[y][x + 1]) {
			fw = "right";
			dfs(square, x + 1, y, num + 1);
		}
	}
}

int main() {

	/**
	* N * N 크기의 배열에 0,0부터 시작해서 시계 방향으로 숫자를 채워나가는 프로그램
	* 
	* -- 자연어 풀이 --
	* 1. n 입력
	* 2. n * n 크기의 2차원 vector 선언
	* 3. 0,0부터 시작해서 x좌표를 늘리며 숫자 채우기
	* 4. dfs 참고해서 사 방향으로 숫자 채우기
	* 5. 오른쪽, 아래, 왼쪽, 위 순서로 채울 때
	* 6. 해당 좌표에 숫자가 이미 채워져 있거나 범위를 벗어나면 return;
	* 
	* -- 추가 수정 사항 --
	* 1. 방향을 인자로 전달
	*/

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		fw = "right";
		vector<vector<int>> square(n, vector<int>(n));
		dfs(square, 0, 0, 1);

		cout << "#" << i + 1 << endl;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cout << square[j][k] << " ";
			}
			cout << endl;
		}
	}
}