#include <iostream>
#include <vector>

#define max_num 100

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int a_size, b_size;
		cin >> a_size >> b_size;

		vector<bool> a(max_num + 1);
		for (int i = 0; i < a_size; i++) {
			int num;
			cin >> num;

			a[num] = true;
		}

		vector<bool> b(max_num + 1);
		for (int i = 0; i < b_size; i++) {
			int num;
			cin >> num;

			b[num] = true;
		}

		string answer = "";
		if (a == b) {
			answer = "=";
		} else if (a_size > b_size) {
			bool check = true;
			for (int i = 0; i < b.size() && check; i++) {
				if (b[i] && !a[i]) {
					check = false;
				}
			}

			if (check) {
				answer = ">";
			}
		} else {
			bool check = true;
			for (int i = 0; i < a.size() && check; i++) {
				if (a[i] && !b[i]) {
					check = false;
				}
			}

			if (check) {
				answer = "<";
			}
		}

		cout << (answer.empty() ? "?" : answer) << "\n";
	}
}