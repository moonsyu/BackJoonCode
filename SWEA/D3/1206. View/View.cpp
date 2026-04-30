#include <iostream>
#include <vector>
#include <algorithm>

#define TC 10

using namespace std;

int main() {
	
	for (int i = 0; i < TC; i++) {
		int n;
		cin >> n;

		vector<long long> aparts(n);
		for (int j = 0; j < n; j++) {
			cin >> aparts[j];
		}
		
		// 조망권 확보까지 2칸 이상 떨어져야 하므로
		// j = 2부터 n - 2까지 탐색
		long long answer = 0;
		for (int j = 2; j < n - 2; j++) {
			// 양 옆의 2칸씩 총 4칸의 아파트 중 가장 높은 층 수 확인
			long long max_floor = max({ aparts[j - 2], aparts[j - 1], aparts[j + 1], aparts[j + 2] });

			// 옆의 아파트가 더 높다면 조망권 확보 실패 -> 0
			// 현재 아파트가 더 높다면 조망권 확보 성공 -> 현재 아파트 층 수 - 가장 높은 층 수
			answer += aparts[j] < max_floor ? 0 : aparts[j] - max_floor;
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}
}