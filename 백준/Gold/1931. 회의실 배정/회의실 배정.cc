#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b) const {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};

int main() {
	/**
	* 회의실에 최대한 많은 회의를 배치하고자 한다
	* 최대 몇개의 회의를 배치할 수 있는가
	* 
	* -- 자연어 풀이 --
	* 1. n을 입력 받는다
	* 2. 회의의 시작 시간과 끝나는 시간을 입력 받는다
	* 3. vector<pair<int, int>>에 회의의 시작 시간과 끝나는 시간을 저장한다
	* 4. 회의의 끝나는 시간을 기준으로 오름차순 정렬한다
	* 5. 회의 시작 시간 <= 다음 회의 시작 시간 < 회의 끝나는 시간에 맞는지 확인한다
	* 6. 조건에 맞는 회의를 선택하고, 선택된 회의의 끝나는 시간을 기준으로 다음 회의를 선택한다
	* 7. 회의를 선택할 때 마다 answer++
	* 8. answer를 출력한다
	* 
	* -- 추가 수정 사항 --
	* 1. dp 사용
	* 2. 회의 시간을 2차원 벡터로 저장 (index: 시작 시간, value: 끝나는 시간) -- 메모리 초과
	* 3. 정렬 기준을 second 우선, first는 second가 같을 때 오름차순으로 정렬
	*/

	int n;
	cin >> n;

	vector<pair<long long, long long>> meetings(n);
	for (int i = 0; i < n; i++) {
		cin >> meetings[i].first >> meetings[i].second;
	}

	sort(meetings.begin(), meetings.end(), cmp());

	long long answer = 0;
	long long end_time = 0;
	for (int i = 0; i < n; i++) {
		if (end_time <= meetings[i].first) {
			end_time = meetings[i].second;
			answer++;
		}
	}

	cout << answer;
}