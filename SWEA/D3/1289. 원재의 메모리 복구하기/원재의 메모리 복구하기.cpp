#include <iostream>
#include <string>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		string memory;
		cin >> memory;

		int answer = 0;
		char now_bit = '0';
		for (int j = 0; j < memory.size(); j++) {
			if (now_bit != memory[j]) {
				answer++;
				now_bit = memory[j];
			}
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}
}