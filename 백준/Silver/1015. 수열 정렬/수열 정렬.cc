/*
* 문제 이해
* 1. A배열의 값을 출력하고자 한다
* 2. P[i] 에는 i번째의 값이 기본적으로 할당이 되어있다
* 3. A[i]의 배열에는 B[p[i]]의 값이 할당된다
* 4. 만약 B 배열의 안에 중복되어 있는 값이 있다면
* (작은 수 부터 차례대로 p[i]번째의 값을 A[i]에 할당한다)
* 5. 입력 -> 첫째줄에 배열의 크기,
*    둘째줄에 배열의 크기만큼 숫자를 입력받는다
* 
* 풀이방법
* 1. P[0] = 0, P[1] = 1인 점을 이용하여 current로 현재 P[i]의 위치를 나타낸다
* 2. 벡터의 크기 N을 입력받고, 그만큼 반복하여 벡터 B에 값을 저장한다
*    이때 vector<pair<string, string>>을 이용하여 첫번째에 값을 두번째에 위치를 저장한다
* 3. 벡터 B를 정렬시킨다
* 4. 벡터 A[B[i].second] = current를 할당한다
* 5. 4번 과정을 N번 반복시키고 반복할때마다 current의 값은 1 증가 하도록 한다
* 6. 벡터 A에 저장된 값을 순서대로 cout << A[i] << " ";시킨다.
**/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int current = 0, N, num;

	cin >> N;
	
	vector<pair<int, int>> B;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> num;
		B.push_back(make_pair(num, i));
	}

	stable_sort(B.begin(), B.end());

	for (int i = 0; i < N; i++) {
		A[B[i].second] = current;
		current++;
	}
	
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
}