#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		vector<long long> num(n);
		for (int j = 0; j < n; j++) {
			cin >> num[j];
		}
		
		vector<long long> memo(n, 1);
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (num[j] <= num[k]) {
					memo[k] = max(memo[k], memo[j] + 1);
				}
			}
		}

		long long answer = 0;
		for (int j = 0; j < n; j++) {
			answer = max(answer, memo[j]);
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}