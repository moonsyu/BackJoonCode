#include <iostream>
#include <vector>

using namespace std;

int main() {

	/**
	* 파스칼의 삼각형 그리기
	* 
	* -- 자연어 풀이 --
	* 1. n을 입력 받는다
	* 2. vector<vector<int>> pascal(n) 선언
	* 3. pascal[0][0] = 1
	* 4. pascal[1][0] = 1, pascal[1][1] = 1
	* 5. 2중 반복문 사용
	* 6. pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]
	* 
	*/

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		vector<vector<int>> pascal(n, vector<int>(n));
		if (n > 0) {
			pascal[0][0] = 1;
		}
		if (n > 1) {
			pascal[1][0] = pascal[1][1] = 1;
		}

		for (int j = 2; j < n; j++) {
			for (int k = 0; k <= j; k++) {
				if (k == 0 || k == j) {
					pascal[j][k] = 1;
				}
				else {
					pascal[j][k] = pascal[j - 1][k - 1] + pascal[j - 1][k];
				}
			}
		}

		cout << "#" << i + 1 << "\n";
		for (vector<int> v : pascal) {
			for (int answer : v) {
				if (answer) {
					cout << answer << " ";
				}
			}
			cout << "\n";
		}
	}
}