#include <iostream>
#include <queue>

using namespace std;

void optimize_io() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}


int main() {
	optimize_io();

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		priority_queue<long long> heap;
		cout << "#" << t;
		for (int i = 0; i < n; i++) {
			int cmd;
			cin >> cmd;

			if (cmd == 1) {
				long long v;
				cin >> v;
				heap.push(v);
			} else if (cmd == 2) {
				if (!heap.empty()) {
					cout << " " << heap.top();
					heap.pop();
				} else {
					cout << " -1";
				}
			}
		}

		cout << "\n";
	}
}