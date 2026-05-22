#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		queue<int> coding;
		for (int i = 0; i < pow(2, n); i++) {
			int num;
			cin >> num;

			coding.push(num);
		}

		long long answer = 0;
		while (coding.size() > 1) {
			int a = coding.front();
			coding.pop();
			int b = coding.front();
			coding.pop();

			answer += abs(a - b);

			if (a > b) {
				coding.push(a);
			} else {
				coding.push(b);
			}
		}
		 
		cout << "#" << t << " " << answer << "\n";
	}
}