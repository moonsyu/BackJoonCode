#include <iostream>
#include <vector>

using namespace std;

vector<int> month = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int m1, d1, m2, d2;
		cin >> m1 >> d1 >> m2 >> d2;

		// m1월 ~ m2월까지의 날짜 계산
		long long answer = 0;
		for (int j = m1; j < m2; j++) {
			answer += month[j];
		}

		// 범위에 포함된 d1일 빼고, 
		// 범위에 포함되지 않은 d2일 더하기
		answer += d2 - d1 + 1;
		cout << "#" << i + 1 << " " << answer << "\n";
	}
}