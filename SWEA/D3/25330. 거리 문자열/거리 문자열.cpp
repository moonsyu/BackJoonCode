#include <iostream>
#include <vector>

#define num_size 10

using namespace std;


/* 등장한 숫자의 개수 조건 충족 여부 (0 or 2)*/
bool num_cnt_check(vector<int> &num_cnt) {

	for (int i = 0; i < num_size; i++) {
		if (num_cnt[i] != 0 && num_cnt[i] != 2) {
			return false;
		}
	}

	return true;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string input;
		cin >> input;

		// 숫자 d가 2번 등장 시
		// 두 숫자 사이에 있는 숫자의 개수 가 d개 인지 확인
		bool check = true;
		vector<int> num_cnt(num_size);
		vector<int> num_idx(num_size);
		for (int i = 0; i < input.size() && check; i++) {

			// 숫자의 등장 횟수 갱신
			int num = input[i] - '0';
			num_cnt[num]++;

			// 숫자가 2번 이상 등장 시
			// 해당 숫자 사이의 숫자 개수 확인
			if (num_cnt[num] > 1 && (i - num_idx[num]) != num + 1) {
				check = false;
			} else {
				// 그 외는 처음 등장하는 숫자기 때문에
				// 등장 인덱스 저장
				num_idx[num] = i;
			}
		}

		bool answer = check && num_cnt_check(num_cnt);
		cout << (answer ? "yes" : "no") << "\n";
	}
}