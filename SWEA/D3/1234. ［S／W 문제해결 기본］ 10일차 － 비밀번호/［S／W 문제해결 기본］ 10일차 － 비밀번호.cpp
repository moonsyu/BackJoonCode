#include <iostream>
#include <vector>

#define tc 10

using namespace std;

int main() {
	
	for (int i = 0; i < tc; i++) {
		int num_size;
		string num_str;
		cin >> num_size >> num_str;

		vector<int> stack;
		for (int j = 0; j < num_size; j++) {
			if (stack.empty()) {
				stack.push_back(num_str[j] - '0');
			} else {
				if (stack.back() == (num_str[j] - '0')) {
					stack.pop_back();
				} else {
					stack.push_back(num_str[j] - '0');
				}
			}
		}

		long long answer = 0;
		for (int j = 0; j < stack.size(); j++) {
			answer *= 10;
			answer += stack[j];
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}
}