#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int b, w, x, y, z;
		cin >> b >> w >> x >> y >> z;

		/**
		* x: 검은 공을 검은 상자의 넣었을 경우 점수
		* y: 흰 공을 흰 상자에 넣었을 경우 점수
		* z: 공와 상자의 색이 다르게 넣었을 경우 점수
		* 
		* -- 자연어 풀이 --
		* 1. 모든 공이 같은 색의 상자에 들어갔을 경우
		*    ㄴ b * x + w * y
		* 2. 모든 공이 다른 상자에 들어갔을 경우
		*    ㄴ (b + w) * z
		* 3. 2. 경우에서 공과 상자의 개수가 다를 경우
		*    ㄴ min(b, w) * z * 2 + abs(b - w) * (b > w ? x : y)
		* 4. 1 ~ 3.의 값들 max 비교
		* 
		* -- 추가 수정 사항 --
		* 1. 2.의 과정은 3.의 식으로 처리가 가능
		*/

		long long answer;
		answer = max(b * x + w * y, min(b, w) * z * 2 + abs(b - w) * (b > w ? x : y));

		cout << answer << "\n";
	}
}