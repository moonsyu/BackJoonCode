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
		int class_cnt = 0;
		for (int j = 0; j < week_size; j++) {
			if (plan[j]) {
				if (start_day == -1) {
					start_day = j;
				}

				class_cnt++;
			}
		}

		// 들어야 하는 주차 및 남은 강의 수 계산
		// (한 주에 강의가 1개일 경우를 고려해 나머지 연산 미사용)
		long long weeks = ((n - 1) / class_cnt);
		int remain = n - weeks * class_cnt;

		// 각 강의 시작일을 두고 남은 강의 수 만큼 강의를 듣는 경우의 수 계산
		int min_remain_day = INT_MAX;
		for (int j = start_day; j < week_size; j++) {

			// 현재 일 기준 남은 강의 수 만큼 강의를 듣는 일 수 계산
			int remain_cnt = 0;
			int temp = remain;
			for (int k = j; temp > 0; k++) {
				if (plan[k % week_size]) {
					temp--;
				}

				remain_cnt++;
			}

			// 가장 적은 일 수로 남은 강의를 들을 수 있는 경우의 수 저장
			min_remain_day = min(min_remain_day, remain_cnt);
		}

		long long answer = weeks * week_size + min_remain_day;
		cout << "#" << i + 1 << " " << answer << "\n";
	}
}