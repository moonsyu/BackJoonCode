#include <iostream>
#include <algorithm>


using namespace std;



struct Work {
	int start;
	int end;
	int cost;

	bool operator<(const Work& other) const {
		if (start == other.start) {
			return end < other.end;
		}
		return start < other.start;
	}
};


int n, m;
Work work[10002];
int max_cost[10002] = {0, };


/* 작업 수익 갱신 */
void cost_calc(int end, int cost) {
	// 작업 수행 가능
	for (int i = end + 1; i <= m + 1; i++) {
		max_cost[i] = max(max_cost[i], cost);
	}
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
		fill(max_cost, max_cost + 10002, 0);
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> work[i].start >> work[i].end >> work[i].cost;
		}

		sort(work, work + n);

		// dp[i].first = i일까지의 최대 수익
		// dp[i].second = i일까지의 작업 수행 가능 여부
		for (int i = 0; i < n; i++) {			
			cost_calc(work[i].end, max_cost[work[i].start] + work[i].cost);

			//output();
		}

		cout << "#" << t << " " << max_cost[m + 1] << "\n";
	}
}