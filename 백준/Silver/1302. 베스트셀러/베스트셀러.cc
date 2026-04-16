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

	vector<string> book(n);

	for (int i = 0; i < n; i++)
		cin >> book[i];

	sort(book.begin(), book.end());

	int count = 0, max = 0;
	string name = "", answer;

	for (int i = 0; i < n; i++) {
		if (name != book[i]) {
			count = 0;
			name = book[i];
		}
		count++;

		if (max < count) {
			max = count;
			answer = name;
		}
	}

	cout << answer;
}