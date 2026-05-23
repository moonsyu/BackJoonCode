#include <iostream>
#include <string>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string n;
		cin >> n;

		if (n[2] - '0' >= 5 && n[2] - '0' <= 9) {
			if (n[1] - '0' + 1 == 10) {
				n[1] = '0';
				if (n[0] - '0' + 1 == 10) {
					n[0] = '0';
				} else {
					n[0] = (n[0] - '0' + 1) + '0';
				}
			} else {
				n[1] = (n[1] - '0' + 1) + '0';
			}
		}

		int cnt = n.size() - 1;
		if (n[0] == '0') {
			n[0] = '1';
			n[1] = '0';
			cnt++;
		} 

		cout << "#" << t << " " << n[0] << "." << n[1] << "*" << 10 << "^" << cnt << "\n";
	}
}