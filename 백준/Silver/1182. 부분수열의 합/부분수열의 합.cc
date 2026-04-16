#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, s, answer = 0;

	cin >> n >> s;

	deque<int> save(n, 0);
	deque<int> visit(n, 0);

	for (int i = 0; i < n; i++)
		cin >> save[i];

	for (int i = n - 1; i > -1; i--) {
		long long sum;
		visit[i] = 1;
		do {
			sum = 0;
			for (int j = 0; j < n; j++) {
				if (visit[j] != 0) {
					//cout << save[j] << " ";
					sum += save[j];
				}
			}
			//cout << "\n";
			if (sum == s)
				answer++;
		} while (next_permutation(visit.begin(), visit.end()));

	}

	cout << answer;
}