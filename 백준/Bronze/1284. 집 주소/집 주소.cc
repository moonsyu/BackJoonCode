#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string num;

	cin >> num;

	while (num != "0") {
		int answer = 0;
		for (int i = 0; i < num.size(); i++) {
			if (num[i] == '1')
				answer += 2;
			else if (num[i] == '0')
				answer += 4;
			else {
				answer += 3;
			}
		}

		cout << answer + num.size() + 1 << "\n";

		cin >> num;
	}
}