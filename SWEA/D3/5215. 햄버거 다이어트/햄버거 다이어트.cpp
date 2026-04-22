#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, l;
		cin >> n >> l;

		vector<pair<long long, long long>> food(n);
		for (int j = 0; j < n; j++) {
			cin >> food[j].first >> food[j].second;
		}

		vector<long long> dp(l + 1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = l; j >= food[i].second; j--) {
				dp[j] = max(dp[j], dp[j - food[i].second] + food[i].first);
			}
		}

		cout << "#" << i + 1 << " " << dp[l] << endl;
	}
}