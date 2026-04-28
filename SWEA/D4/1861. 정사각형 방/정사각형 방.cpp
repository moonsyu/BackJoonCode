#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

void dfs(vector<vector<long long>>& square, vector<vector<long long>>& visit, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 이동 범위 확인
		if (nx < 0 || nx >= square.size() || ny < 0 || ny >= square.size()) {
			continue;
		}

		// 이동 가능한지 확인
		if (square[nx][ny] == square[x][y] + 1) {
			// 만약 아직 지나가지 않은 길 이라면
			if (!visit[nx][ny]) {
				dfs(square, visit, nx, ny);
			}
		
			// 방문기록 갱신
			visit[x][y] = visit[nx][ny] + 1;
		}
	}
}


int main() {
	/**
	* -- 자연어 풀이 --
	* 1. 2차원 배열을 입력받는다.
	* 2. 각 칸에 이동한 기록이 없다면 (0이라면) 사방을 확인한다
	* 3. 사방에 이동이 가능하다면 해당 칸에 값을 확인한다
	* 4. 해당 칸에 값이 있다면 값 + 1, 없다면 이동
	* 5. 각 칸으로 이동 시 몇칸을 넘어왔는지 인자로 기록한다
	* 6. 더 이상 이동이 불가능할 경우 이동한 칸 수를 기록한다
	* 
	* -- 추가 수정 사항 --
	* 1. 방문 기록 시 이동한 칸의 값 + 1을 현재 칸에 기록
	* 2. 방문 기록이 더 클 경우 최대 방문 횟수 및 인덱스 갱신
	* 3. 같을 경우 인덱스만 작은 값으로 갱신
	*/


	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		vector<vector<long long>> square(n, vector<long long>(n));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> square[j][k];
			}
		}

		long long index = LLONG_MAX;
		long long answer = 0;
		vector<vector<long long>> visit(n, vector<long long>(n));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				// 방문 기록이 없을 경우 dfs 탐색
				if (!visit[j][k]) {
					dfs(square, visit, j, k);
				}

				if (visit[j][k] > answer) {
					answer = visit[j][k];
					index = square[j][k];
				} else if (visit[j][k] == answer) {
					index = min(index, square[j][k]);
				}
			}
		}

		cout << "#" << i + 1 << " " << index << " " << (answer ? answer + 1 : 0) << endl;
	}
}