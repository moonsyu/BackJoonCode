#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	deque<deque<pair<char, long long>>> save(n, deque<pair<char, long long>>(m, make_pair(' ', 0)));
	deque<long long> alphabet(26, 0);

	for (int i = 0; i < n; i++) {
		string msg;
		cin >> msg;
		for (int j = 0; j < m; j++) {
			save[i][j].first = msg[j];
		}
	}

	int del = 0;
	for (int i = 0; i < m; i++) {
		del += i;
		for (int j = 0; j < n; j++) {
			save[j][i].second += (m * (i + 1) - del) * 2;
			save[j][m - i - 1].second += (m * (i + 1) - del) * 2;
		}
	}

	//for (int i = 0; i < n; i++)
	//	for(int j = 0; j < m; j++)
	//		cout << save[i][j].first << " " << save[i][j].second << "\n";

	deque<long long> cnt(n, 0);

	del = 0;
	for (int i = 0; i < n; i++) {
		del += i;
		cnt[i] += (n * (i + 1) - del) * 2;
		cnt[n - i - 1] += (n * (i + 1) - del) * 2;
	}


	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			alphabet[save[i][j].first - 65] += (save[i][j].second * cnt[i]);
			//cout << cnt[i] << "\n";
		}

	for (int i = 0; i < alphabet.size(); i++)
		cout << alphabet[i] << "\n";
}