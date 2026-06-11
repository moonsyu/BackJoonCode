#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int len;
		cin >> len;

		cout << "#" << tc << " ";
		cout << (len % 2 ? "Bob" : "Alice") << "\n";
	}
}