#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		vector<int> light(101, 0);
		for (int i = a; i < b; i++) {
			light[i]++;
		}

		for (int i = c; i < d; i++) {
			light[i]++;
		}

		int answer = 0;
		for (int i = 0; i < light.size(); i++) {
			if (light[i] == 2) {
				answer++;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}