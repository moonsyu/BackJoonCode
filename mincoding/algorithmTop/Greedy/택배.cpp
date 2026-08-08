#include <iostream>
#include <algorithm>

using namespace std;


struct Delivery {
	int start; // 시작 마을
	int end;   // 도착 마을
	int count; // 배송할 택배 수
};


/* 시작 마을 -> 도착 마을 기준 정렬 */
struct delivery_cmp {
	bool operator()(Delivery& a, Delivery& b) {
		if (a.end == b.end) {
			return a.start < b.start;
		}
		
		return a.end < b.end;
	}
};


int n, c, m;
Delivery info[10001];

int answer = 0;
int truck[2001];

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> c >> m;

	for (int i = 0; i < m; i++) {
		cin >> info[i].start >> info[i].end >> info[i].count;
	}

	sort(info, info + m, delivery_cmp());
	fill(truck, truck + 2001, c);

	for (int i = 0; i < m; i++) {
		auto [start, arrive, box] = info[i];
		for (int j = start; j < arrive; j++) {
			box = min(box, truck[j]);
		}

		for (int j = start; j < arrive; j++) {
			truck[j] -= box;
		}

		answer += box;
	}

	cout << answer << "\n";
}
