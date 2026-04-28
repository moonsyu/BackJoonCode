#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;

		cout << "#" << i + 1 << " " << min(p * w, q + max(0, w - r) * s) << endl;
	}
}