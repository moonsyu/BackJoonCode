#include <iostream>
#include <vector>

#define tc 10
#define max_height 100
#define max_width 100

using namespace std;

/* 가장 높게 쌓인 상자의 인덱스 반환 */
int find_max_idx(vector<int>& box) {
	for (int i = max_height - 1; i >= 0; i--) {
		if (box[i]) {
			return i;
		}
	}
}


/* 가장 낮게 쌓인 상자의 인덱스 반환 */
int find_min_idx(vector<int>& box) {
	for (int i = 0; i < max_height; i++) {
		if (box[i]) {
			return i;
		}
	}
}


int main() {

	for (int i = 0; i < tc; i++) {
		int dump;
		cin >> dump;

		vector<int> box(max_height);
		for (int j = 0; j < max_width; j++) {
			int temp;
			cin >> temp;

			box[temp - 1]++;
		}

		int max_idx = 0, min_idx = 0;
		for (int j = 0; j <= dump; j++) {
			max_idx = find_max_idx(box);
			min_idx = find_min_idx(box);

			// 평탄화가 완료된 경우 반복문 탈출
			if (max_idx - min_idx < 2) {
				break;
			}

			// 가장 높게 쌓인 상자에서 1개 빼서
			box[max_idx]--;
			box[max_idx - 1]++;

			// 가장 낮게 쌓인 상자에 1개 추가
			box[min_idx]--;
			box[min_idx + 1]++;
		}

		cout << "#" << i + 1 << " " << max_idx - min_idx << endl;
	}

}