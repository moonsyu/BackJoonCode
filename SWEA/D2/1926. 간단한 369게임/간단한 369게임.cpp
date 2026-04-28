#include <iostream>

using namespace std;

int main() {
	/**
	* 1 ~ n까지 숫자를 차례로 출력한다
	* 이때 3, 6, 9가 포함된 수는 숫자 대신 해당 수의 개수 만큼 -를 출력한다
	* 
	* -- 자연어 풀이 --
	* 1. n을 입력 받는다
	* 2. 1부터 n까지 반복문을 돌린다
	* 3. 현재 수 != 0이 아니면, 
	*    현재 수가 0이 될 때까지 반복문을 돌린다
	* 4. 이때 현재 숫자를 10으로 나눈 나머지가 3, 6, 9 중 하나라면 count++
	* 5. count가 0이 아니라면, count만큼 -를 출력한다
	* 6. count가 0이라면, 현재 숫자를 출력한다
	* 
	*/

	long long n;
	cin >> n;

	for (long long i = 1; i <= n; i++) {
		long long num = i;

		long long count = 0;
		while (num != 0) {
			if ((num % 10 ? num % 10 : 1) % 3 == 0) {
				count++;
			}

			num /= 10;
		}

		if (count) {
			for (long long j = 0; j < count; j++) {
				cout << '-';
			}
		} else {
			cout << i;
		}

		cout << " ";
	}
}