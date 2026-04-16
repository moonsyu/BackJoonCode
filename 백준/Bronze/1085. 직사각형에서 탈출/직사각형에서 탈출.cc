#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int x, y, w, h, a;

	cin >> x >> y >> w >> h;

	if (w == x || y == h)
		cout << 0;
	else {
		if (w - x < x)
			a = w - x;
		else
			a = x;
		if (y > h - y && a > h - y)
			a = h - y;
		else if (a > y)
			a = y;
		cout << a;
	}
}