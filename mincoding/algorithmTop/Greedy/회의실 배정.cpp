#include <iostream>
#include <algorithm>

using namespace std;


struct Meeting {
    int start;
    int end;
};


/* 종료 시간 기준 오름차순 정렬 */
struct compare {
    bool operator() (Meeting a, Meeting b) {
        return a.end < b.end;
    }
};

int n;
Meeting info[100000];

int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
		cin >> info[i].start >> info[i].end;
    }

	sort(info, info + n, compare());

    int answer = 0;
    int end_time = 0;
    for (int i = 0; i < n; i++) {
		if (info[i].start >= end_time) {
            answer++;
			end_time = info[i].end;
		}
    }

    cout << answer;
}
