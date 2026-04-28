#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 기본 값 초기화
	vector<int> dp(n + 1);
	for (int i = 0; i < 3; i++) {
		dp[i] = -1;
	}

	if (n >= 3) 
		dp[3] = 1;
	if (n >= 4)
		dp[4] = -1;
	if (n >= 5)
		dp[5] = 1;

	// dp 점화식
	for (int i = 6; i <= n; i++) {
		if (dp[i - 3] == -1 && dp[i - 5] == -1) {
			dp[i] = -1;
		} else if (dp[i - 3] == -1) {
			dp[i] = dp[i - 5] + 1;
		} else if (dp[i - 5] == -1) {
			dp[i] = dp[i - 3] + 1;
		} else {
			dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
		}
	}

	cout << dp[n];
}