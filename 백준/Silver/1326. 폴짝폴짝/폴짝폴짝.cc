#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;

	cin >> n;

	vector<int> rock(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> rock[i];

	int a, b;

	cin >> a >> b;

	vector<bool> check(10001, true);
	queue<pair<int, int>> que;
	que.push(make_pair(a, 1));

	while (!que.empty() && a != b) {
		//cout << que.front().first << "\n";
		a = que.front().first;

		if ((b - a) % rock[a] == 0)
			break;
		else {
			int count = que.front().second;

			for (int i = rock[a]; a + i < n + 1; i += rock[a])
				if (check[a + i]) {
					que.push(make_pair(a + i, count + 1));
					check[a + i] = false;
				}

			for (int i = rock[a]; a - i > 0; i += rock[a])
				if (check[a - i]) {
					que.push(make_pair(a - i, count + 1));
					check[a - i] = false;
				}
		}

		que.pop();
	}

	if (que.empty())
		cout << -1;
	else if (a == b)
		cout << 0;
	else
		cout << que.front().second;
}