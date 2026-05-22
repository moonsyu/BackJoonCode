#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<int> jumps(n);
		for (int i = 0; i < n; i++) {
			cin >> jumps[i];
		}

		sort(jumps.begin(), jumps.end());

		vector<int> new_set;
		for (int i = 0; i < n; i += 2) {
			new_set.push_back(jumps[i]);
		}

		if (n % 2) {
			for (int i = n - 2; i > 0; i -= 2) {
				new_set.push_back(jumps[i]);
			}
		} else {
			for (int i = n - 1; i > 0; i -= 2) {
				new_set.push_back(jumps[i]);
			}
		}

		int answer = abs(new_set[0] - new_set[n - 1]);
		for (int i = 0; i < n - 1; i++) {
			answer = max(answer, abs(new_set[i] - new_set[i + 1]));
		}

		cout << "#" << t << " " << answer << "\n";
	}
}