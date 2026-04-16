#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s;

	cin >> s;

	vector<int> answer(26, 0);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > 96) {
			answer[s[i] - 97]++;
		}
		else {
			answer[s[i] - 65]++;
		}
	}
	
	int max = 0;
	char ans = '?';

	for (int i = 0; i < 26; i++) {
		if (answer[i] > max) {
			max = answer[i];
			ans = i + 65;
		}
		else if (answer[i] == max)
			ans = '?';
	}

	cout << ans;
}