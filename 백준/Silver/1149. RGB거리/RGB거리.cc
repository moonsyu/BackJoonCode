#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<long long>> color(n + 1, vector<long long>(3));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}

	vector<vector<long long>> dp(n + 1, vector<long long>(3));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1) {
				dp[i][j] = color[i][j];
			} else {
				dp[i][j] = color[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
			}
		}
	}

	cout << min({dp[n][0], dp[n][1], dp[n][2]});
}