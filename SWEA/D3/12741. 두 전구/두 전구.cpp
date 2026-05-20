#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		// 켜진 시간 정렬
		vector<pair<int, int>> light;
		light.push_back({ a, b });
		light.push_back({ c, d });

		sort(light.begin(), light.end());

		int answer = 0;
		// 시간 배치: a ~~~~~~~~~ b
		//               c ~~~ d
		if (light[0].second >= light[1].second) {
			answer = light[1].second - light[1].first;
		} 
		// 시간 배치: a ~ b  c ~ d
		else if (light[0].second < light[1].first) {
			answer = 0;
		} 
		// 시간 배치: a ~~~~~ b
		//                c ~~~~~ d
		else {
			answer = light[0].second - light[1].first;
		}

		cout << "#" << t << " " << answer << "\n";
	}
}