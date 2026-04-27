#include <iostream>
#include <vector>

using namespace std;

vector<int> money = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

int main() {
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		int n;
		cin >> n;

		cout << "#" << i << "\n";
		for (int j = 0; j < money.size(); j++) {
			cout << n / money[j] << " ";
			n %= money[j];
		}

		cout << "\n";
	}
}