/*
* 문제 이해
* 1. 집합 S가 주어진다
* 2. A < B인 조건을 만족하는 A <= x <= B에 집합 S가 속해있지 않다면 좋은구간이다
* 3. n이 주어졌을때 n이 포함된 좋은 구간의 개수를 구하자
* 
* 문제풀이
* 1. 첫째줄에 S의 크기 L이 주어진다
* 2. 둘째줄에는 S집합에 포함된 정수가 주어진다
* 3. 셋째줄에는 n이 주어진다
* 4. S집합을 정렬한다
* 5. S집합에서 n이 들어 갈수 있는 구간을 찾는다
*    (반복문을 통해 S[i] > n보다 클 경우를 찾는다)
* 6. S[i - 1]과 S[i] 사이에서 S[i - 1] + 1 <= n <= S[i] - 1의 개수를 찾는다
* 7. 
**/

#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	deque<int> S;

	int L, n;

	cin >> L;

	for (int i = 0; i < L; i++) {
		int num;
		cin >> num;
		S.push_back(num);
	}
	sort(S.begin(), S.end());

	cin >> n;
	int index = 0;
	for (int i = 0; i < L; i++) {
		if (S[i] > n) {
			index = i;
			break;
		}
	}
	int count = 0;

	if (index < 1) {
		for (int i = 1; i <= n; i++)
			for (int j = n; j < S[index]; j++)
				count++;

		if (S[index] != n)
			cout << count - 1;
		else
			cout << 0;

	}
	else {
		for (int i = S[index - 1] + 1; i <= n; i++)
			for (int j = n; j < S[index]; j++)
				count++;

		if (S[index - 1] != n)
			cout << count - 1;
		else
			cout << 0;
	}

}