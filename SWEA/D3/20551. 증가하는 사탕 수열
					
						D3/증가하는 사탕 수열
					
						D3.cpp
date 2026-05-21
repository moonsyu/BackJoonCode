#include <iostream>
#include <vector>

#define box_cnt 3

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		vector<int> box(box_cnt + 1);
		for (int i = 1; i <= box_cnt; i++) {
			cin >> box[i];
		}

		/**
		* 박스에는 최소 1개 이상의 사탕이 있어야 한다
		* 또한 i + 1 번째 박스 안에는 i 번째 박스보다 많은 사탕이 있어야 한다
		* 
		* 때문에 각 박스 번호보다 적은 개수의 사탕이 박스 안에 있을 경우 불가능 하다
		* 이를 큰 박스번호때 부터 세어 들어간다.
		* 
		* -- 추가 수정 사항 --
		* 1. i번째 상자에 들어있는 사탕 수는 i + 1번째 상자에 들어있는 사탕 수 보다 1개만 적으면 된다
		*/

		int answer = 0;
		for (int i = box_cnt; i > 0; i--) {
			if (box[i] < i) {
				answer = -1;
				break;
			} 

			if (i < box_cnt) {				
				if (box[i] > box[i + 1] - 1) {
					answer += box[i] - (box[i + 1] - 1);
					box[i] = box[i + 1] - 1;
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}