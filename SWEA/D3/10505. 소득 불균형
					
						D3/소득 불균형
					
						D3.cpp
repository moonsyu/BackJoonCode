#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		long long total_price = 0;
		vector<int> price(n);
		for (int i = 0; i < n; i++) {
			cin >> price[i];
			total_price += price[i];
		}

		// 평균 소득
		long long middle_price = total_price / n;

		// 평균 소득보다 낮은 사람 수 카운팅
		int answer = 0;
		for (int i = 0; i < n; i++) {
			if (price[i] <= middle_price) {
				answer++;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}