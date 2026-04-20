#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	/**
	* 왼쪽부터 오른쪽으로 이동하는 동안
	* 가장 적은 비용으로 주유할 때
	* 주유 비용의 최소 값을 구하라
	*
	* -- 자연어 풀이 --
	* 1. 맨 왼쪽에서 다음 위치로 갈 때 드는 주유 비용을 계산한다
	* 2. 그 다음 위치로 이동할 때 드는 주유 비용을 계산한다 (i + 1 * 주유소 가격)
	* 3. 현재 위치에서 주유하는게 더 싸다면 계산 후 2번을 반복한다
	* 4. 다음 위치가 더 싸다면 해당 위치로 이동 후 2번을 반복한다
	*
	* -- 추가 수정 사항 --
	* 1. 주유 가격만 비교하면 된다
	* 2. 주유 가격이 가장 싼 곳을 저장한 다음 위치로 이동할 때 드는 주유 비용을 계산한다
	*/

	int n;
	cin >> n;

	vector<long long> distance(n - 1);
	vector<long long> city(n);

	for (int i = 0; i < n - 1; i++) {
		cin >> distance[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> city[i];
	}
	
	long long answer = 0;
	long long min_price = city[0];
	for (int i = 0; i < n - 1; i++) {
		if (min_price <= city[i]) {
			answer += min_price * distance[i];
		} else {
			min_price = city[i];
			answer += min_price * distance[i];
		}
	}

	cout << answer;
}