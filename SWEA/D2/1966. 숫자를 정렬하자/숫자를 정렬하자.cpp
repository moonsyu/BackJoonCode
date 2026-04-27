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

		sort(num.begin(), num.end());

		cout << "#" << i + 1 << " ";
		for (int j = 0; j < n; j++) {
			cout << num[j] << " ";
		}
		cout << "\n";
	}
}