#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


/* 이동 비용 정보 계산 */
vector<pair<long long, pair<int, int>>> calc_distance(vector<pair<int, int>>& location) {
	vector<pair<long long, pair<int, int>>> distance;
	
	for (int i = 0; i < location.size(); i++) {
		for (int j = i + 1; j < location.size(); j++) {
			long long dist = pow(location[i].first - location[j].first, 2) + pow(location[i].second - location[j].second, 2);
			distance.push_back({ dist, {i, j} });
		}
	}

	sort(distance.begin(), distance.end());

	return distance;
}


/* 최상위 부모 조회 */
int find_parent(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return x;
	}

	return find_parent(parent, parent[x]);
}


/* 최상위 노드의 부모 변경 */
void change_parent(vector<int>& parent, int a, int b) {
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		vector<pair<int, int>> location(n);
		for (int j = 0; j < n; j++) {
			cin >> location[j].first;
		}

		for (int j = 0; j < n; j++) {
			cin >> location[j].second;
		}

		long double e;
		cin >> e;

		// 이동 비용 계산
		vector<pair<long long, pair<int, int>>> distance;
		distance = calc_distance(location);

		// 부모 노드 초기화
		vector<int> parent(n);
		for (int j = 0; j < n; j++) {
			parent[j] = j;
		}

		// 크루스칼 알고리즘
		long long answer = 0;
		for (int j = 0; j < distance.size(); j++) {
			int root_a = find_parent(parent, distance[j].second.first);
			int root_b = find_parent(parent, distance[j].second.second);

			if (root_a != root_b) {
				answer += distance[j].first;

				change_parent(parent, root_a, root_b);
			}
		}

		cout << "#" << i + 1 << " " << (long long)(answer * e + 0.5) << "\n";
	}
}