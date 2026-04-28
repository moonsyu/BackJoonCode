#include <iostream>
#include <vector>

using namespace std;

// ※ 미해결 ※
int main() {
	/**
	* 
	* 동아리 부원들이 동아리 실을 사용할 수 있는 경우의 수 구하기
	* 
	* 출력 시 1000000007로 나눈 나머지 출력
	* 부원: 4명
	* 열쇠: A가 보유
	* 
	* -- 자연어 풀이 --
	* 1. 일자별 동아리 담당자 문자열을 받는다
	* 2. 각 일자를 인덱스로 하여 vector에 동아리 담당자를 넣는다
	* 3. 탐색은 1부터 문자열 길이만큼 실행하나, vector의 인덱스 0에는 A(열쇠 보유자)를 넣는다
	* 4. vector<long long> dp(n + 1)을 선언하여 경우의 수를 저장한다
	* 5. 경우의 수 저장 시 1000000007로 나눈 나머지를 저장한다
	* 6. 현재 일자의 담당자가 전날과 같다면, dp[i] = dp[i - 1] * fow(2, 3) - 1
	* 7. 현재 일자의 담당자가 전날과 다르다면, dp[i] = dp[i - 1] * fow(2, 2) - 1
	* 
	* -- 추가 수정 사항 -- A, B, C, D가 있을 때
	* 1. 오늘을 기준으로 내일 방문자를 확인 후 경우의 수를 구하자
	*    ㄴ 오늘과 내일 담당자가 같다면 dp[i] = dp[i - 1] * 2^3
	*    ㄴ 오늘과 내일 담당자가 다르다면 dp[i] = dp[i - 1] * 2^2
	* 2. 둘째날 담당자가 첫째날 담당자와 같다면 dp[1] = dp[0] * 2^3
	* 3. 둘째날 담당자가 첫째날 담당자와 다르다면 dp[1] = dp[0] * 2^2
	*    ㄴ 여기서 첫째날에 둘째날 담당자가 방문해 있을 경우의 수를 제거한다
	* 4. vector를 2개로 나눈다 
	*    ㄴ 하나는 전날 방문자가 현재 담당자와 같을 경우
	*       ㄴ dp[i - 1] * 2^3
	*    ㄴ 하나는 전날 방문자가 현재 담당자와 다를 경우
	*       ㄴ dp[i - 1] * 2^2
	*    ㄴ 각각의 vector를 계산 후 dp[vector.size()]의 값을 더한다
	*/


	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		string str;
		cin >> str;

		vector<string> club(str.size() + 1);
		club[0] = "A";

		for (int j = 0; j < str.size(); j++) {
			club[j + 1] = str[j];
		}

		vector<long long> dp(str.size() + 1, 1);
		for (int j = 1; j <= str.size(); j++) {
			if (j == 1) {
				if (club[j] == "A") {
					dp[j] = (dp[j - 1] * (8)) % 1000000007;
				} else {
					dp[j] = (dp[j - 1] * (4)) % 1000000007;
				}
			}
			else {
				if (club[j] == club[j - 1]) {
					dp[j] = (dp[j - 1] * (8)) % 1000000007;
				} else {
					dp[j] = (dp[j - 1] * (8)) % 1000000007;
				}
			}
		}

		for (long long a : dp) {
			cout << a << " ";
		}
		cout << "\n";

		cout << "#" << i + 1 << " " << dp[str.size()] << "\n";
	}
}