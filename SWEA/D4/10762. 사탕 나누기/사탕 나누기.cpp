#include <iostream>

using namespace std;

int n;
int input;
int min_num;
long long result, sum;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n;

		cin >> input;
		sum = result = min_num = input;
		for (int i = 1; i < n; i++) {
			cin >> input;

			sum += input;
			min_num = min(min_num, input);
			result ^= input;
		}

		cout << "#" << t << " ";
		if (result) {
			cout << "NO" << "\n";
		} else {
			cout << sum - min_num << "\n";
		}
	}
}