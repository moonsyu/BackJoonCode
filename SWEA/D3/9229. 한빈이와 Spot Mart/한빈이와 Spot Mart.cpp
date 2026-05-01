#include <iostream>
#include <vector>
#include <algorithm>

#define item_cnt 2

using namespace std;

long long answer;
long long limit;

/* 내림차순 정렬 */
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};


/* item_cnt 만큼 물건 선택 후 합 계산 */
void dfs(vector<long long>& a, int idx, int cnt, long long sum) {

	// 물건을 item_cnt 만큼 선택한 경우
	if (cnt == item_cnt) {
		answer = max(answer, sum);
		return;
	}

	for (int i = idx; i < a.size(); i++) {
		if (sum + a[i] <= limit) {
			dfs(a, i + 1, cnt + 1, sum + a[i]);
		}
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n >> m;

		vector<long long> a(n);
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}

		//// 내림차순 정렬
		//sort(a.begin(), a.end(), cmp());

		//long long answer = -1;
		//for (int j = 0; j < n; j++) {
		//	for (int k = j + 1; k < n; k++) {
		//		if (a[j] + a[k] <= m) {
		//			answer = max(answer, a[j] + a[k]);
		//		}
		//	}
		//}


		answer = -1;
		limit = m;
		dfs(a, 0, 0, 0);

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}