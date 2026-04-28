#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> grade = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

int main() {
	int tc;
	cin >> tc;
	
	for (int i = 0; i < tc; i++) {
		int n, k;
		cin >> n >> k;

		vector<long long> score(n);
		for (int j = 0; j < n; j++) {
			int mid, fin, hw;
			cin >> mid >> fin >> hw;

			score[j] = mid * 35 + fin * 45 + hw * 20;
		}

		int target = score[k - 1];
		sort(score.begin(), score.end(), greater<int>());

		for (int j = 0; j < score.size(); j++) {
			if (score[j] == target) {
				cout << "#" << i + 1 << " " << grade[(j / (n / 10))] << "\n";
				break;
			}
		}
		
	}
}