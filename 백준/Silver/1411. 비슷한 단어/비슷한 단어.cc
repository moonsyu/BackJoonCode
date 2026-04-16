#include<iostream>
#include<deque>
#include<map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, count = 0;
	deque<string> text;
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		string msg;
		cin >> msg;
		text.push_back(msg);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			map<char, char> change;
			map<char, char> r_change;
			bool check = true;
			for (int k = 0; k < text[i].size(); k++) {
				if (change.find(text[i][k]) == change.end()) {
					change[text[i][k]] = text[j][k];
				}
				else if (change[text[i][k]] != text[j][k]) {
					check = false;
					break;
				}

				if (r_change.find(text[j][k]) == r_change.end()) {
					r_change[text[j][k]] = text[i][k];
				}
				else if (r_change[text[j][k]] != text[i][k]) {
					check = false;
					break;
				}

			}
			if (check)
				count++;
		}
	}

	cout << count;
}