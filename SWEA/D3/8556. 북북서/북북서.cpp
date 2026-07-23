#include <iostream>

using namespace std;

int stack_idx;
int fw[20];

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string s;
		cin >> s;

		stack_idx = 0;
		for (int i = 0; i < s.size(); ) {
			if (s[i] == 'n') { // 북쪽
				fw[stack_idx++] = 1;
				i += 5;
			}
			else { // 서쪽
				fw[stack_idx++] = 0;
				i += 4;
			}
		}

		long long  num, divide;
		divide = 1 << (stack_idx - 1); // 분모
		num = fw[stack_idx - 1] ? 0 : 90 * divide; // 분자

		// 분모를 통분하여 역순 계산
		long long val = 90 * divide / 2;
		for (int i = stack_idx - 2; i >= 0; i--) {
			if (fw[i]) { // 북쪽
				num -= val;
			}
			else { // 서쪽
				num += val;
			}
			val /= 2;
		}

		// 기약분수 만들기
		while (!(num % 2) && divide > 1) {
			num /= 2;
			divide /= 2;
		}

		cout << "#" << t << " ";
		if (divide == 1)
			cout << num << "\n";
		else
			cout << num << "/" << divide << "\n";
	}
}