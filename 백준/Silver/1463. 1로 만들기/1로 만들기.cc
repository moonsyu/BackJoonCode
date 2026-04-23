#include <iostream>
#include <vector>

using namespace std;

int main() {
	/**
	* 정수 x가 주어졌을 때 1로 만드는 최소한의 연산 횟수를 구하라
	* 
	* 연산 방법
	* 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
	* 2. X가 2로 나누어 떨어지면, 2로 나눈다.
	* 3. 1을 뺀다.
	* 
	* -- 자연어 풀이 --
	* 1. n을 입력 받는다
	* 2. n + 1 사이즈의 1차원 dp를 만든다
	* 3. dp[0] = 0; dp[1] = 0; dp[2] = 1; dp[3] = 1;로 초기화 한다
	* 4. 4 ~ n까지 반복하며 min(dp[i/3], dp[i/2], dp[i-1]) + 1을 계산한다
	* 5. dp[n] 출력한다
	*/


	int n;
	cin >> n;

	vector<long long> dp(n + 1, 0);
	if(n >= 2) 
		dp[2] = 1;
	if(n >= 3) 
		dp[3] = 1;

	for (int i = 4; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) 
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) 
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[n];
}