#include <iostream>
#include <vector>

using namespace std;

vector<int> prime = { 2, 3, 5, 7, 11 };

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		cout << "#" << i + 1 << " ";
		for (int j = 0; j < prime.size(); j++) {
			int cnt = 0;
			while (n % prime[j] == 0) {
				n /= prime[j];
				cnt++;
			}

			cout << cnt << " ";
		}

		cout << endl;
	}
}