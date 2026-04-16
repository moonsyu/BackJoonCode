/*
* 문제이해
* 1. 요세푸스 순열
* 2. N명의 사람과 K가 주어진다
* 3. K번째 사람이 빠지고 다음 K번째 사람이 순서대로 빠진다
* 4. 7 명의 사람이 3의 간격으로 빠진다고 했을때
* 1 2 3 4 5 6 7
* 1 2 4 5 6 7 -> 3
* 1 2 4 5 7 -> 3, 6
* 1 4 5 7 -> 3, 6, 2
* 1 4 5 -> 3, 6, 2, 7
* 1 4 -> 3, 6, 2, 7, 5
* 4 -> 3, 6, 2, 7, 5, 1
* 
* 문제풀이
* 1. n과 k를 입력받는다
* 2. 시작 번째를 변수에 저장해 둔다 start = k - 1
* 3. 참가자들의 번호를 받을 deque를 선언한다
* 4. deque에는 참가자 들의 번호를 순서대로 저장한다
* 5. deque[start]의 값을 출력한다
* 6. deque.erase(deque.begin() + start)로 해당 인덱스를 제거한다
* 7. start += k를하고 n -= 1을 하여 최대 인원수를 1만큼 줄인다 
* 8. 만약 start > n 다면 start -= n;
* 9. 5. ~ 8.까지 deque.empty() == true일때까지 반복한다
**/


#include<iostream>
#include<deque>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;

	cin >> n >> k;

	deque<int> people;
	
	for (int i = 1; i <= n; i++)
		people.push_back(i);

	int start = k - 1;

	cout << "<";
	while (people.empty() != true) {

		while (start >= n && n != 0)
			start -= n;

		cout << people[start];
		people.erase(people.begin() + start);

		start += (k - 1);
		n -= 1;

		if (!people.empty())
			cout << ", ";

		//cout << start << " " << n << "\n";
	}
	cout << ">";
}