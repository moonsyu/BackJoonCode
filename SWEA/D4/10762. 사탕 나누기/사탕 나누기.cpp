#include <iostream>
#include <string>

using namespace std;

int n;
int min_num;
long long result, sum;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n;

		sum = 0;
		result = 0;
		min_num = 1000001;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			sum += num;
			min_num = min(min_num, num);
			result = (result ? result ^ num : num);
		}

		cout << "#" << t << " ";
		if (result) {
			cout << "NO" << "\n";
		} else {
			cout << sum - min_num << "\n";
		}
	}
}