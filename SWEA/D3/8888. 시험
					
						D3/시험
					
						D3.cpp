#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* 정렬 조건 */
struct cmp {
	bool operator() (pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
		// 점수와 푼 문제의 개수가 같을 경우
		if (a.first == b.first) {
			return a.second < b.second;
		}
		
		// 점수가 같을 경우 문제 푼 순 내림차순 정렬
		if (a.first.first == b.first.first) {
			return a.first.second > b.first.second;
		} 

		// 점수 기반 내림차순 정렬
		return a.first.first > b.first.first;
	}
};


/* 문제 풀이 결과 입력 */
vector<vector<int>> input_(int n, int t) {

	vector<vector<int>> result(n, vector<int>(t));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < t; j++) {
			cin >> result[i][j];
		}
	}

	return result;
}


/* 각 문제의 점수 반환 */
vector<int> get_score(vector<vector<int>>& test) {

	vector<int> result;
	for (int i = 0; i < test[0].size(); i++) {

		int score = 0;
		for (int j = 0; j < test.size(); j++) {
			if (!test[j][i])
				score++;
		}

		result.push_back(score);
	}

	//cout << "score result\n";
	//for (int i = 0; i < result.size(); i++) {
	//	cout << result[i] << " ";
	//}
	//cout << "\n\n";

	return result;
}


/* 각 참가자의 점수, 푼 문제 수, 참가자 번호 반환 */
vector<pair<pair<int, int>, int>> clac_info(vector<vector<int>>& test, vector<int>& score) {

	vector<pair<pair<int, int>, int>> result;
	for (int i = 0; i < test.size(); i++) {
		int sum = 0;
		int cnt = 0;
		for (int j = 0; j < test[i].size(); j++) {
			if (test[i][j]) {
				sum += score[j];
				cnt++;
			}
		}

		result.push_back({ { sum, cnt }, i + 1 });
	}

	//cout << "info result\n";
	//for (int i = 0; i < result.size(); i++) {
	//	cout << result[i].first.first << " " << result[i].first.second << " " << result[i].second << "\n";
	//}
	//cout << "\n\n";


	return result;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int tc_num = 1; tc_num <= tc; tc_num++) {
		int n, t, p;
		cin >> n >> t >> p;
		
		// 문제 풀이 결과 입력
		vector<vector<int>> test = input_(n, t);

		// 각 문제의 점수 계산
		vector<int> score = get_score(test);

		// 각 인원의 점수, 푼 문제 수, 번호 계산
		vector<pair<pair<int, int>, int>> test_result = clac_info(test, score);

		// 조건 별 등수 정렬
		sort(test_result.begin(), test_result.end(), cmp());

		// 결과 출력
		for (int i = 0; i < test_result.size(); i++) {
			if (test_result[i].second == p) {
				cout << "#" << tc_num << " " << test_result[i].first.first << " " << i + 1 << "\n";
				break;
			}
		}
	}
}