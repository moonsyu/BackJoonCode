#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		int answer = 0;
		for (int j = 0; j <= n; j++) {
			if (j % 2) {
				answer += j;
			} else {
				answer -= j;
			}
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}
}