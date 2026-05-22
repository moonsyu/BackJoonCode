#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define max_city_size 1000

using namespace std;

struct City {
	long long x, y, s;
};


/* 부모 탐색 */
int find_parent(vector<int>& parent, int idx) {
	if (parent[idx] == -1) {
		return -1;
	} else if (parent[idx] == idx) {
		return idx;
	} else {
		return parent[idx] = find_parent(parent, parent[idx]);
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<int> parent(n);
		vector<City> city(n);
		for (int i = 0; i < n; i++) {
			cin >> city[i].x >> city[i].y >> city[i].s;
			parent[i] = i;
		}

		// i는 j에게 위협 받는다
		for (int i = 0; i < n; i++) {
			long long max_s = 0;
			long long max_d = 1;
			long long target = -1;
			long long max_cnt = 0;

			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}

				long long s = city[j].s;
				long long d = pow(city[i].x - city[j].x, 2) + pow(city[i].y - city[j].y, 2);

				// max_s / max_d == s / d 이므로
				// max_s * d = s * max_d 가 성립한다
				if (max_s * d == s * max_d) {
					max_cnt++;
				} else if (max_s * d < s * max_d) {
					max_s = s;
					max_d = d;
					target = j;
					max_cnt = 1;
				}
			}

			// 본인의 군사력보다 위협이 더 클 때
			if (city[i].s * max_d < max_s) {
				if (max_cnt == 1) {
					parent[i] = target;
				} else {
					parent[i] = -1;
				}
			}
		}

		cout << "#" << t;
		for (int i = 0; i < n; i++) {
			int result = find_parent(parent, i);
			if (result == -1) {
				cout << " D";
			}
			else if (result == i) {
				cout << " K";
			}
			else {
				cout << " " << result + 1;
			}
		}
		cout << "\n";
	}
}