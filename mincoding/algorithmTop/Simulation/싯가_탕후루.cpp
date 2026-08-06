#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

long long n;
int people_cnt[1000001] = { 0, };
int price[100000] = { 0, };
int stack_idx = 0;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);


	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		
		// 해당 가격의 처음 구매의사를 표시한 경우
		// distinct_cnt 증가 및 price 배열에 가격 기록
		if (!people_cnt[temp]) {
			price[stack_idx++] = temp;
		}

		// 해당 가격의 구매의사 인원 수 추가
		people_cnt[temp]++;
	}

	// 구매 의상 가격표 오름차순 정렬
	sort(price, price + stack_idx);

	// 낮은 가격부터 계산
	long long total_price = price[0] * n; // 가장 낮은 가격의 총 수익 계산
	long long min_price = price[0]; // 최소 가격
	for (int i = 1; i < stack_idx; i++) {
		n -= people_cnt[price[i - 1]]; // 해당 가격으로 구매 못하는 인원수 제외
		if (total_price < price[i] * n) {
			total_price = price[i] * n;
			min_price = price[i];
		}
	}

	cout << total_price << " " << min_price << "\n";
}
