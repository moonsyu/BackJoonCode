#include <iostream>

using namespace std;


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);


	int area[6][6];
	for (int i = 0; i < 6;i++) {
		for (int j = 0; j < 6;j++) {
			cin >> area[i][j];
		}
	}


	int answer = -63;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			int sum = 0;
			sum += area[i][j];
			sum += area[i - 1][j - 1] + area[i - 1][j] + area[i - 1][j + 1];
			sum += area[i + 1][j - 1] + area[i + 1][j] + area[i + 1][j + 1];
			
			answer = max(answer, sum);
		}
	}

	cout << answer;
}
