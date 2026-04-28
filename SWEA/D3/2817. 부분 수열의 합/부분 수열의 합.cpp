#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long answer = 0;

void dfs(vector<long long>& num, long long sum, int i, int k) {
	if (sum == k) {
		answer++;
		return;
	}

	if (sum > k) {
		return;
	}

	for (int j = i; j < num.size(); j++) {
		dfs(num, sum + num[j], j + 1, k);
	}
}

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, k;
		cin >> n >> k;

		vector<long long> num(n);
		for (int j = 0; j < n; j++) {
			cin >> num[j];
		}

		dfs(num, 0, 0, k);
		
		cout << "#" << i + 1 << " " << answer << "\n";
		answer = 0;
	}
}