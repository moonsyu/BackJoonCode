#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* 내림차순 정렬 */
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n >> m;

		vector<long long> a(n);
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}

		// 내림차순 정렬
		sort(a.begin(), a.end(), cmp());

		long long answer = -1;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[j] + a[k] <= m) {
					answer = max(answer, a[j] + a[k]);
				}
			}
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}