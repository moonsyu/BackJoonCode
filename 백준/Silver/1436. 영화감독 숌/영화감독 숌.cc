#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int count, a;

	cin >> n;

	a = 5666;

	if (n < 7)
		cout << (n - 1) * 1000 + 666;

	else {
		count = 0;
		while (count + 6 != n) {
			a++;
			if (a % 1000 == 666 || a % 10000 - a % 10 == 6660 || a % 100000 - a % 100 == 66600 || a % 1000000 - a % 1000 == 666000)
				count++;
		}
		cout << a;
	}
}