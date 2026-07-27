#include <iostream>

using namespace std;


int find_bell_idx(string bell) {
	for (int i = 0; i < bell.size(); i++) {
		if (bell[i] == 'o') {
			return i;
		}
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string bell;
		int ring_cnt;
		cin >> bell >> ring_cnt;

		cout << "#" << t << " ";
		int bell_idx = find_bell_idx(bell);
		if (bell_idx == 2) {
			if (!ring_cnt) {
				cout << 2 << "\n";
			} else {
				bell_idx--;
				ring_cnt--;
			}
		} 

		if (bell_idx == 0) {
			cout << (ring_cnt % 2 ? 1 : 0) << "\n";
		}
		else if (bell_idx == 1) {
			cout << (ring_cnt % 2 ? 0 : 1) << "\n";
		}
	}
}