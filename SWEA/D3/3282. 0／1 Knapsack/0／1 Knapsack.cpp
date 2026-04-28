#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, k;
		cin >> n >> k;

		// 무게: v, 가치: c
		vector<int> v(n + 1);
		vector<int> c(n + 1);
		for (int j = 1; j <= n; j++) {
			cin >> v[j] >> c[j];
		}

		vector<int> dp(k + 1);
		for (int j = 1; j <= n; j++) {
			for (int l = k; l >= 0; l--) {
				if (l >= v[j]) {
					dp[l] = max(dp[l], dp[l - v[j]] + c[j]);
				}
			}
		}

		cout << "#" << i + 1 << " " << dp[k] << endl;
	}
}