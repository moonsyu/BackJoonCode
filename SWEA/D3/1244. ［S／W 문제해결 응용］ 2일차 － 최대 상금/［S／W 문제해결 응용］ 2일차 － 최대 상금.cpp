#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long answer = 0;


/* 현재 위치부터 가장 큰 수 찾기 */
int find_max_num(vector<int> v, int s_idx) {
	int max_num = 0;
	for (int i = s_idx; i < v.size(); i++) {
		max_num = max(max_num, v[i]);
	}

	return max_num;
}


/* 연속된 수 확인 */
bool has_same_num(vector<int> num_list) {
	for (int i = 0; i < num_list.size() - 1; i++) {
		if (num_list[i] == num_list[i + 1]) {
			return true;
		}
	}

	return false;
}


/* vector -> answer 변환 */
long long calc_answer(vector<int>& num_list) {
	long long result = 0;
	for (int i = 0; i < num_list.size(); i++) {
		result *= 10;
		result += num_list[i];
	}

	return result;
}


/* dfs */
void dfs(vector<int>& num_list, int idx, int change_count) {

	// 교환 횟수가 모두 소진되었거나
	// 모든 탐색을 마쳤을 경우
	if (!change_count || idx >= num_list.size() - 1) {
		// 연속된 수가 없고, 교환 횟수가 홀수일 경우, 뒤 2자리 교환
		if (!has_same_num(num_list) && (change_count % 2)) {
			swap(num_list[num_list.size() - 2], num_list[num_list.size() - 1]);
		} 

		answer = max(answer, calc_answer(num_list));
		return;
	}

	// 현재 위치부터 가장 큰 수 찾기
	int max_num = find_max_num(num_list, idx);

	// 가장 큰 수가 현재 위치에 있을 경우, 다음 위치 탐색
	if (num_list[idx] == max_num) {
		dfs(num_list, idx + 1, change_count);
	}
	else {
		for (int i = idx; i < num_list.size(); i++) {

			// 가장 큰 수와 현재 수의 위치 교환
			if (num_list[i] == max_num) {
				swap(num_list[i], num_list[idx]);
				dfs(num_list, idx + 1, change_count - 1);
				swap(num_list[i], num_list[idx]);
			}
		}
	}
}


int main() {
	/**
	* 최대 6자리의 숫자와 최대 10번의 교환이 주어질 때,
	* 모든 교환 횟수를 사용해서 만들 수 있는
	* 가장 큰 수를 구하라
	* 
	* -- 자연어 풀이 --
	* 1. tc 입력
	* 2. tc만큼 반복
	* 3. 숫자와 교환 횟수 입력
	* 4. 숫자를 배열로 변환
	* 5. 0 ~ n - 1 까지 탐색하며
	* 6. 가장 큰 수를 찾는다
	* 7. 현재 위치부터 재 탐색하며 가장 큰 수와 같은 수를 찾을경우 위치 교환 및 교환 횟수++
	* 8. 이를 n - 1번째 위치까지 반복하며
	* 9. dfs를 통해 구현한다
	* 10. 교환 횟수가 남았을 경우, 
	* 11. 0 ~ n - 1까지 탐색하며 동일한 수가 있을 경우 탐색을 종료한다
	* 12. 동일한 수가 없을 경우, n - 1과 n - 2 번째 수를 교환하는걸 반복한다
	* 13. 교환 횟수가 없을 경우 max(answer, 수);
	* 14. answer 출력
	* 
	* -- 추가 수정 사항 --
	* 1. 교환 횟수가 수의 길이보다 크더라도 탐색을 돌린다
	* 2. idx가 n - 1보다 크거나 같을 경우도 answer를 계산한다
	*    ㄴ 이떄, 남은 교환 횟수가 홀수라면 뒤 2자리를 교환한다
	*    ㄴ 남은 교환 횟수가 짝수라면 그대로 둔다
	*/


	int tc; 
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		string n;
		int change_count;
		cin >> n >> change_count;

		vector<int> num_list(n.size());
		for (int j = 0; j < n.size(); j++) {
			num_list[j] = n[j] - '0';
		}

		answer = 0;
		dfs(num_list, 0, change_count);


		cout << "#" << i + 1 << " " << answer << "\n";
	}
}