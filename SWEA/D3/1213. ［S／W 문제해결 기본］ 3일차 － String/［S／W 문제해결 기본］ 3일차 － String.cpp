#include <iostream>
#include <string>

#define tc 10

using namespace std;

int main() {
	
	for (int i = 0; i < tc; i++) {
		int t;
		cin >> t;

		string word, text;
		cin >> word >> text;

		long long answer = 0;
		for (int j = 0; j <= text.size() - word.size(); j++) {
			if (text.substr(j, word.size()) == word) {
				answer++;
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
}