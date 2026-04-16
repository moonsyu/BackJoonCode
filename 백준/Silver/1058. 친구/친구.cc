#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;

	cin >> n;

	vector<vector<int>> count(n, vector<int>(0, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char yn; cin >> yn;
			if (yn == 'Y') {
				count[i].push_back(j);
			}
		}
	}


	int answer = 0;
	for (int i = 0; i < n; i++) {
		vector<bool> visit(n, true);
		int cnt = 0;
		visit[i] = false;

		for (auto& j : count[i]) {
			if (visit[j]) {
				visit[j] = false;
				cnt++;

			}
			for (auto& k : count[j]) {
				if (visit[k]) {
					visit[k] = false;
					cnt++;
				}
			}
		}

		answer = max(answer, cnt);
	}

	//for (auto& i : count) {
	//	for (auto& j : i) {
	//		cout << j << " ";
	//	}
	//	cout << "\n";
	//}

	cout << answer;
}