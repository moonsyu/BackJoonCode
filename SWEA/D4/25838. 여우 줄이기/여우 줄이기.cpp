#include <iostream>
#include <string>
#include <vector>

#define find_text "fox"

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		string input;
		cin >> input;

		
		vector<int> stack;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == 'f') {
				stack.push_back(i);
			}
		}

		string text = find_text;
		while (!stack.empty()) {
			int idx = stack.back();
			stack.pop_back();

			if (input.substr(idx, text.size()) == find_text) {
				input.erase(idx, text.size());
			}
		}

		cout << input.size() << "\n";
	}
}