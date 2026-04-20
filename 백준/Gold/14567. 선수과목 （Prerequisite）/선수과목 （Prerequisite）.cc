#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	/**
	* N개의 과목이 주어지고, 각 과목의 선수 과목이 주어진다
	* 각 과목을 수강할 수 있는 학기를 구하라
	* 
	* 출력은 1번 과목 ~ n번 과목까지 각 과목을 수강할 수 있는 학기를 출력한다
	* 
	* -- 자연어 풀이 --
	* 1. n, m 입력
	* 2. n + 1 크기의 2차원 vector 선언
	* 3. m번 반복하면서 선수 과목 입력
	* 4. b번 과목의 인덱스에 a번 과목을 push_back
	* 5. for문으로 1 ~ n번 과목까지 반복하면서 각 과목의 선수 과목이 있는지 확인
	* 6. 선수 과목이 있다면 que에 선수 과목과 학기 push
	* 7. que가 빌 때까지 반복하면서 que의 front를 pop
	* 8. pop한 과목의 선수 과목이 있는지 확인
	* 9. que가 비었다면 마지막에 수강된 학기를 출력
	* 
	* -- 추가 수정 사항 --
	* 1. 선수 과목이 언제나 숫자가 작다는걸 활용
	* 2. 과목 수강 학기를 저장할 vector 선언
	*/


	int n, m;
	cin >> n >> m;

	vector<vector<int>> prereq(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		prereq[b].push_back(a);
	}

	vector<int> semester(n + 1, 0);
	for (int i = 1; i < prereq.size(); i++) {
		if (prereq[i].size()) {
			for (int j = 0; j < prereq[i].size(); j++) {
				semester[i] = max(semester[i], semester[prereq[i][j]] + 1);
			}
		} else {
			semester[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << semester[i] << " ";
	}
}