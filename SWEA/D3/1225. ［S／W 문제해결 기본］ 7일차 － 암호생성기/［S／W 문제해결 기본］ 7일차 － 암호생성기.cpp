#include <iostream>
#include <queue>

#define tc 10
#define input_size 8
using namespace std;

int main() {
	
	for (int i = 0; i < tc; i++) {
		int t;
		cin >> t;

		queue<int> que;
		for (int j = 0; j < input_size; j++) {
			int num;
			cin >> num;
			que.push(num);
		}

		int cnt = 0;
		while (true) {
			int now = que.front();
			que.pop();

			cnt = ++cnt % 5 ? cnt % 5 : 5;
			if (now - cnt <= 0) {
				que.push(0);
				break;
			} else {
				que.push(now - cnt);
			}
		}

		cout << "#" << t << " ";
		while (!que.empty()) {
			cout << que.front() << " ";
			que.pop();
		}
		cout << endl;
	}
}