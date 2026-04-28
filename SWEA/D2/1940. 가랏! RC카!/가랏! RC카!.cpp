#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		int speed, answer;
		speed = answer = 0;
		for (int j = 0; j < n; j++) {
			int option, value;
			cin >> option;

			if (option) {
				cin >> value;
			}

			if (option == 1) {
				speed += value;
			} else if (option == 2) {
				speed = speed - value < 0 ? 0 : speed - value;
			}

			answer += speed;
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}