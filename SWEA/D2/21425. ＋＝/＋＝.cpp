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
	* 2. a += b를 반복하며 a가 n을 초과할 때 횟수를 저장한다
	* 3. b += a를 반복하며 b가 n을 초과할 떄 까지 횟수를 구한다
	* 4. 2, 3에서 구한 횟수 중 작은 값을 출력한다
	* 
	* -- 추가 수정 사항 --
	* 1. a와 b 중 작은 값에 큰 값을 +=
	* 2. 2번 과정을 반복한다
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