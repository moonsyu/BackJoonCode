#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define week_size 7

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		// 일주일 강의 계획
		vector<int> plan(week_size);
		for (int j = 0; j < week_size; j++) {
			cin >> plan[j];
		}

		// 강의 시작일 및 1주간 강의 개수 조회
		int start_day = -1;
		for (int j = 0; j < week_size; j++) {
			if (plan[j] && start_day == -1) {
				start_day = j;
			}
		}

		// 각 강의 시작일에 대해 n개의 강의를 듣기 위한 최소 일수 계산
		long long answer = LLONG_MAX;
		for (int j = start_day; j < week_size; j++) {
			long long day_cnt = 0;
			int class_cnt = n;
			for (int k = j; class_cnt > 0; k++) {
				day_cnt++;

				if (plan[k % week_size]) {
					class_cnt--;
				}
			}

			answer = min(answer, day_cnt);
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}