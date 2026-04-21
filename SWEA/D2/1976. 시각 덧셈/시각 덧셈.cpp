#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;

		int time = (h1 + h2) * 60 + m1 + m2;
		int hour = time / 60 % 12 ? time / 60 % 12 : 12;
		int minute = time % 60;
		cout << "#" << i + 1 << " " << hour << " " << minute << "\n";
	}
}