#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<int> forward(n);
		for (int i = 0; i < n; i++) {
			cin >> forward[i];
		}

		// 모든 체크포인트 방문 시 이동 거리
		int max_len = 0;
		for (int i = 0; i < n - 1; i++) {
			max_len += abs(forward[i] - forward[i + 1]);
		}

		// i + 1번째 체크포인트 미방문 처리
		int answer = max_len;
		for (int i = 0; i < n - 2; i++) {
			int pre_move_value = abs(forward[i] - forward[i + 1]) + abs(forward[i + 1] - forward[i + 2]);
			int now_move_value = abs(forward[i] - forward[i + 2]);

			answer = min(answer, max_len - pre_move_value + now_move_value);
		}

		cout << answer << endl;
	}
}