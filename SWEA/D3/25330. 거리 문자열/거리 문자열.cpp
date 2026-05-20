#include <iostream>
#include <vector>

#define num_size 10

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string input;
		cin >> input;

		bool answer = true;
		vector<int> num_cnt(num_size);
		vector<int> num_idx(num_size);
		for (int i = 0; i < input.size() && answer; i++) {
			
			int num = input[i] - '0';
			num_cnt[num]++;

			if (num_cnt[num] > 1) {
				if ((i - num_idx[num]) != num + 1) {
					answer = false;
				}
			} else {
				num_idx[num] = i;
			}
		}

		// 숫자가 0번 or 2번 나왔는지 확인
		for (int i = 0; i < num_size && answer; i++) {
			if (num_cnt[i] != 0 && num_cnt[i] != 2) {
				answer = false;
			}
		}

		if (answer) {
			cout << "yes";
		} else {
			cout << "no";
		}
		cout << "\n";
	}
}