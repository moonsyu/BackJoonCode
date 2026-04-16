/*
* 문제이해
* 1. 같은 크기의 배열 A와 B가 있다
* 2. 배열의 크기를 입력받는다
* 3. A 배열에 들어갈 원소를 입력받는다
* 4. B 배열에 들어갈 원소를 입력받는다
* 5. A와 B배열에 있는 원소들중 하나씩 골라 곱한다
* 6. 곱한 값들을 모두 합하여 최솟값이 되도록 하라
* 단. 배열 B는 정렬하지 않도록 한다
* 
* 풀이방법
* 1. N(벡터의 크기)을 입력받는다
* 2. 벡터 A와 B를 선언한다
* 3. 1.만큼 반복하면서 A에 값을 입력받는다
* 4. 1.만큼 반복하면서 B에 값을 입력받는다
* 5. 벡터 A르 정렬시킨다
* 6. B에서 가장큰 수와 해당 수가 들어간 인덱스를 찾는다
* 7. 6.의 정보를 저장하기위해 max와 index를 선언하여 사용한다
* 8. S += max * A[i]를 하고 벡터 B에서 max값이 저장된 index를 삭제한다
* 9. 6. ~ 8.을 N만큼 반복한다
**/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int N, S = 0;

	cin >> N;

	vector<int> A;
	vector<int> B;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		B.push_back(num);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		int max =  -1, index = 0;

		for (int j = 0; j < B.size(); j++) {
			if (B[j] >= max) {
				max = B[j];
				index = j;
			}
		}
		S += max * A[i];

		B.erase(B.begin() + index);
	}

	cout << S;

}