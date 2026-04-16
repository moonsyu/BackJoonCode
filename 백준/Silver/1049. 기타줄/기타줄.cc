/*
* 문제이해
* 1. 기타줄이 끊어졌다
* 2. 끊어진 기타줄의 개수를 보고
* 3. 가장 적은돈으로 가장 효율적으로 살수있는 최솟값을 구하라
* 4. 끊어진 기타줄(N)    브랜드수(M)    의 순으로 입력을 받고
* 5. 6개 묶음가격         개당가격      의 순으로 입력을 받는다
* 
* 문제풀이
* 1. N(끊어진 기타줄의 개수) 와 M(브랜드 수)를 입력받는다.
* 2. M만큼 반복하여 6개 패키지 가격과 개당 가격을 입력받는다
* 3. 반복 한번당 입력을 2번 받는다
* 4. 첫번째 입력은 패키지 가격을 저장할 vector에 pair<패키지가격 / 6 * N, 패키지가격>으로 저장한다
* 5. 두번째 입력은 개당 가격을 저장할 vector에 개당가격을 저장한다
* 6. vector 두개를 정렬시킨다
* 7. vector package[0]와 vector single[0]을 이용한다
* 8. if(package[0].first < single[0]){
*		sum += N/6 * package[0].second;
*		if(package[0].second < single[0] * N % 6)
*			sum += package[0].second;
*		else
*			sum += single[0] * N % 6;
*	 }
*	 else
*		sum += single[0] * N;
* 
**/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	vector<pair<double, int>> package;
	vector<int> single;

	for (int i = 0; i < M; i++) {
		int num;

		cin >> num;
		package.push_back(make_pair(num / 6, num));

		cin >> num;
		single.push_back(num);
	}

	sort(package.begin(), package.end());
	sort(single.begin(), single.end());

	int sum = 0;

	if (package[0].first < single[0]) {
		sum += N / 6 * package[0].second;
		if (package[0].second < single[0] * (N % 6)) {
			sum += package[0].second;
		}
		else
			sum += single[0] * (N % 6);
	}
	else
		sum += single[0] * N;

	cout << sum;

}