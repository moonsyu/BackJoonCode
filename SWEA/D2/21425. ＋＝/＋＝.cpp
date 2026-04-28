#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	/**
	* a, b, n을 입력 받았을 때
	* a += b or b += a를 반복하여 n을 초과하는 최소 횟수를 구하라
	* 
	* -- 자연어 풀이 --
	* 1. a, b, n을 입력 받는다
	* 2. a와 b 중 작은 값에 큰 값을 +=
	* 3. 2번 과정을 반복한다
	* 
	*/

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int a, b, n;
		cin >> a >> b >> n;

		int answer = 0;
		while (!(a > n || b > n)) {
			if (a > b) 
				b += a;
			else 
				a += b;

			answer++;
		}

		cout << answer << "\n";
	}

}