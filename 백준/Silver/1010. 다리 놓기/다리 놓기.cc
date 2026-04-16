#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		unsigned long long a, b, answer = 1, count = 0;
		cin >> a >> b;

		for (int j = b; count++ < b - a; j--) {
			answer *= j;
			answer /= count;
		}
		cout << answer << "\n";
	}

}