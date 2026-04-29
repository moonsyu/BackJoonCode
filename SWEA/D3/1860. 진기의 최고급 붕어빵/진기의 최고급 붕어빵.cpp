#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> people(n);
		for (int j = 0; j < n; j++) {
			cin >> people[j];
		}

		// 사람들이 도착하는 시간을 오름차순으로 정렬
		sort(people.begin(), people.end());

		bool answer = true;
		for (int j = 0; j < n; j++) {
			// 방문 시간 별 붕어빵 개수 계산
			// 시간별 붕어빵 제조 개수: people[j] / m * k
			// 판매된 붕어빵 개수: sell_cnt
			if (people[j] / m * k - j <= 0) {
				answer = false;
				break;
			}
		}

		// 판매 가능 여부 출력
		if (answer) {
			cout << "#" << i + 1 << " Possible" << endl;
		} else {
			cout << "#" << i + 1 << " Impossible" << endl;
		}
	}
}
