#include <iostream>
#include <string>

using namespace std;


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string input;
		cin >> input;

		int answer = 0;
		int start_idx = 0;
		int end_idx = input.size() - 1;
		while (start_idx < end_idx) {
			if (input[start_idx] == input[end_idx]) {
				start_idx++;
				end_idx--;
			} else if (input[start_idx] == 'x') {
				answer++;
				start_idx++;
			} else if (input[end_idx] == 'x') {
				answer++;
				end_idx--;
			} else {
				answer = -1;
				break;
			}
		}

		cout << answer << "\n";
	}
}