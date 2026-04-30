#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 내림차순 정렬
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, k;
		cin >> n >> k;

		vector<int> grades(n);
		for (int j = 0; j < n; j++) {
			cin >> grades[j];
		}

		sort(grades.begin(), grades.end(), cmp());

		long long answer = 0;
		for (int j = 0; j < k; j++) {
			answer += grades[j];
		}

		cout << "#" << i + 1 << " " << answer << "\n";
	}
}