#include <iostream>
#include <string>

using namespace std;


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string str;
		cin >> str;

		int answer = 1;
		for (int s_len = 1; s_len <= str.size(); s_len++) {

			// 남은 문자열의 길이가 
			// 비교 문자열의 배수일 경우 로직 실행
			if (!(str.size() % (s_len))) {

				// 비교 문자열의 길이만큼 반복하여 비교
				bool check = true;
				for (int j = s_len; j < str.size() && check; j++) {
					// ex) str = "abcabcabc", s_len = 3, j = 3 일 떄,
					// j의 범위는 3 ~ 5이고, str[j % s_len]의 범위는 0 ~ 2이다.
					// 이를 통해 str[j]와 str[j % s_len]를 비교하여 반복되는 문자열인지 확인한다.
					if (str[j] != str[j % s_len]) {
						check = false;
					}
				}

				// 반복되는 문자열이 맞을 경우
				// 전체 길이 / 비교 문자열 == 반복 횟수이다.
				if (check) {
					answer = str.size() / s_len;
					break;
				}
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
}