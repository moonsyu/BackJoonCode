#include <iostream>
#include <vector>

using namespace std;


/* 좌표 추가 계산 (값 기준) */
void make_location(vector<pair<int, int>>& location, int end) {

	for (int i = location.size(); i <= end; i++) {
		int x = location.back().first;
		int y = location.back().second;

		if (y == 1) {
			y = x + 1;
			x = 1;
		} else {
			x++;
			y--;
		}

		location.push_back({ x, y });
	}
}


int main() {
	/**
	* 1사분면 기준, 대각선 순서대로 각 좌표에 번호를 매긴다
	* ex) (1, 1) -> 1, (2, 1) -> 2, (1, 2) -> 3, (3, 1) -> 4 ...
	* 
	* 좌표 계산식을 새로 만드려고 할 때, 주어진 두 수 기준의 계산 값을 구하라
	* 
	* 계산식
	* p*q -> p의 좌표 + q의 좌표 -> (px + qx, py + qy)의 값
	* 
	* -- 자연어 풀이 --
	* 1. p와 q를 입력 받아 p와 q의 좌표를 구한다
	*    ㄴ 1차원 vector의 인덱스를 기준으로 구한다
	*    ㄴ pair<int, int>로 좌표를 저장한다
	*    ㄴ first와 second가 동일하다면, first를 올린 후 second를 1로 초기화 한다
	*    ㄴ 이를 p or q와 동일한 인덱스 까지 반복한다.
	* 2. p와 q의 좌표를 구한 후 더한다.
	* 3. 더한 좌표 값을 기준으로 vector 내에서 탐색한다.
	*/

	int tc;
	cin >> tc;

	// 기본값 초기화
	vector<pair<int, int>> location;
	location.push_back({ 0, 0 }); 
	location.push_back({ 1, 1 });

	for (int i = 0; i < tc; i++) {
		int p, q;
		cin >> p >> q;

		// p의 좌표을 구하지 않은 상태일 경우
		if (p >= location.size()) {
			make_location(location, p);
		}

		// q의 좌표를 구하지 않은 상태일 경우
		if (q >= location.size()) {
			make_location(location, q);
		}

		// 목표 좌표 계산
		int x = location[p].first + location[q].first;
		int y = location[p].second + location[q].second;

		// 결과값이 location에 존재하지 않을 경우, location 확장
		while (x + y > location.back().first + location.back().second) {
			make_location(location, location.size() * 2);
		} 

		for (int j = location.size() - 1; j >= 0; j--) {
			if (location[j].first == x && location[j].second == y) {
				cout << "#" << i + 1 << " " << j << "\n";
				break;
			}
		}
	}
}