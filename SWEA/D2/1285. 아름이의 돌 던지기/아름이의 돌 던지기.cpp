#include <iostream>
#include <queue>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		return abs(a) > abs(b);
	}
};

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		priority_queue<int, vector<int>, compare> pq;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;

			pq.push(abs(num));
		}

		long long cnt = 0;
		long long answer = pq.top();
		while (!pq.empty() && pq.top() == answer) {
			cnt++;
			pq.pop();
		}

		cout << "#" << i + 1 << " " << answer << " " << cnt << endl;
	}
}