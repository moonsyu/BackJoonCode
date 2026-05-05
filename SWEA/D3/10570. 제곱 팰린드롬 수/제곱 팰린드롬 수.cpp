#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


/* 팰린 드롬 수 여부 확인 */
bool palindrome_check(int num) {
	string s = to_string(num);

	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}

	return true;
}


int main() {
	int tc;
	cin >> tc;

	// 0은 0개
	vector<int> palindrome_cnt(1, 0);
	for (int i = 0; i < tc; i++) {
		int a, b;
		cin >> a >> b;

		// b까지 팰린드롬 수의 개수 저장
		if (palindrome_cnt.size() <= b) {
			int start = palindrome_cnt.size();
			palindrome_cnt.resize(b + 1);

			for (int j = start; j <= b; j++) {

				// 제곱 팰린드롬 수가 가능한 수 인지 확인
				if (j == (int)sqrt(j) * (int)sqrt(j)) {
					// 팰린드롬 수 이자, 제곱 팰린드롬 수 인지 확인
					if (palindrome_check(j) && palindrome_check((int)sqrt(j))) {
						palindrome_cnt[j] = palindrome_cnt[j - 1] + 1;
					}
					else {
						palindrome_cnt[j] = palindrome_cnt[j - 1];
					}
				} else {
					palindrome_cnt[j] = palindrome_cnt[j - 1];
				}
			}
		}

		cout << "#" << i + 1 << " " << palindrome_cnt[b] - palindrome_cnt[a - 1] << "\n";
	}
}