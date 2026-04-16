#include<iostream>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string str;

	getline(cin, str);

	bool word_check = false, blank_check = true;
	int answer = 0;
	for (auto& s : str) {
		if (s != ' ')
			word_check = true;
		else {
			word_check = false;
			blank_check = true;
		}

		if (word_check && blank_check) {
			answer++;
			word_check = blank_check = false;
		}
	}

	cout << answer;
}