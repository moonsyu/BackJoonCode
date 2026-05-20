#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		// 좌표 정렬
		vector<pair<int, int>> light;
		light.push_back({ a, b });
		light.push_back({ c, d });

		sort(light.begin(), light.end());

		int answer = 0;
		if (light[0].second >= light[1].second) {
			answer = light[1].second - light[1].first;
		} else if (light[0].second < light[1].first) {
			answer = 0;
		} else {
			answer = light[0].second - light[1].first;
		}

		cout << "#" << t << " " << answer << "\n";
	}
}