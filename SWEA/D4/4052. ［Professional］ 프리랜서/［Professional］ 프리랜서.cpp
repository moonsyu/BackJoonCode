#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
vector<int> max_cost(10002, 0);

/* 작업 수익 갱신 */
void cost_calc(int end, int cost) {
	// 작업 수행 가능
	for (int j = end + 1; j <= m + 1; j++) {
		max_cost[j] = max(max_cost[j], cost);
	}
}


/* 이전 작업까지의 최대 수익 계산 */
int search_max_cost(int start) {

	return max_cost[start];
}


/* 디버깅 용 */
void output() {
	cout << "--------------------\n";
	for (int i = 0; i <= m + 1; i++) {
		cout << max_cost[i] << " ";
	}
	cout << "\n";
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		fill(max_cost.begin(), max_cost.end(), 0);
		cin >> n >> m;

		// 작업 정보 {{start_day, end_day}, cost}
		vector<pair<pair<int, int>, int>> work(n);
		for (int i = 0; i < n; i++) {
			cin >> work[i].first.first >> work[i].first.second >> work[i].second;
		}

		// 작업 정보를 시작일 기준으로 정렬
		sort(work.begin(), work.end());

		//cout << "\n\n";
		//for (int i = 0; i < n; i++) {
		//	cout << work[i].first.first << " " << work[i].first.second << " " << work[i].second << "\n";
		//}


		// dp[i].first = i일까지의 최대 수익
		// dp[i].second = i일까지의 작업 수행 가능 여부
		for (int i = 0; i < n; i++) {
			auto [start, end] = work[i].first;
			int cost = work[i].second;
			
			int max_cost = search_max_cost(start);
			cost_calc(end, max_cost + cost);

			//output();
		}

		cout << "#" << t << " " << max_cost[m + 1] << "\n";
	}
}