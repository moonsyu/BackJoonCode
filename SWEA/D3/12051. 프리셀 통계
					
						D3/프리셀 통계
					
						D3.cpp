#include <iostream>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		long long n, pd, pg;
		cin >> n >> pd >> pg;

		/**
		* 오늘 많아야 n 판을 했다 즉 1 ~ n까지 판 수 탐색이 진행 되어야 한다
		* pd와 pg는 각각 오늘한 판 수에서 이긴 퍼센트와 여태까지 한 판 수에서 이긴 퍼센트 이다
		* 
		* g는 언제나 d보다 많거나 같아야 한다 d <= g
		* 
		* g는 여태까지 한 판들의 수이다
		* 그러므로 g가 100일 경우 오늘 d도 100 이어야 가능하다
		* 하지만 g가 100이 아닐경우 d와 pd가 몇이든 상관 없이 그만큼의 승률을 만들 수 있다. 
		* 
		* -- 추가 수정 사항 --
		* 1. pg가 0일 떄 pd가 0이 아닐 경우도 불가능 하다
		* 2. 1 ~ n 사이의 횟수 중 pd 확률의 승리 횟수가 정수로 떨어지는 횟수가 있어야 한다.
		* 
		*/


		bool check = false;
		for (int i = 1; i <= n && !check; i++) {
			if (i * pd * 1.0 / 100 == i * pd / 100) {
				check = true;
			}
		}

		cout << "#" << t << " " << (check ? ((pg == 100 && pd != 100) || (pg == 0 && pd != 0) ? "Broken\n" : "Possible\n") : "Broken\n");
	}
}