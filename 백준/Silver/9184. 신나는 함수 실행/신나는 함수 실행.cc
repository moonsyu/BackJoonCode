#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 21

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	vector<vector<vector<long long>>> dp(MAX_SIZE, vector<vector<long long>>(MAX_SIZE, vector<long long>(MAX_SIZE)));

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) {
			break;
		} else if (a <= 0 || b <= 0 || c <= 0) {
			cout << "w(" << a << ", " << b << ", " << c << ") = 1\n";
		} else {
			cout << "w(" << a << ", " << b << ", " << c << ") = ";
			if (a > 20 || b > 20 || c > 20) {
				a = b = c = 20;
			} else {
				a = min(a, 20);
				b = min(b, 20);
				c = min(c, 20);
			}

			for (int i = 0; i <= min(a, 20); i++) {
				for (int j = 0; j <= min(b, 20); j++) {
					for (int k = 0; k <= min(c, 20); k++) {
						if (i == 0 || j == 0 || k == 0) {
							dp[i][j][k] = 1;
						} else if (i < j && j < k) {
							dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
						} else {
							dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
						}
					}
				}
			}

			cout << dp[a][b][c] << "\n";
		}
	}
}