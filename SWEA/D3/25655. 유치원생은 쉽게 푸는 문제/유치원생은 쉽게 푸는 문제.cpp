#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		string answer = "";
		// n이 홀수일 때
		if (n % 2) {
			// 1이라면 0,
			// 그 외 4로 시작
			if (n == 1) {
				answer = "0";
			} else {
				answer = "4";
			}
		}

		// 나머지 부분 8로 채우기
		for (int i = 0; i < n / 2; i++) {
			answer += "8";
		}

		cout << answer << endl;
	}
}