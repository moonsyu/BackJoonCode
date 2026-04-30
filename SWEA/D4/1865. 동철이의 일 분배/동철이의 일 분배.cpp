#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


double answer = 0;

void dfs(vector<vector<double>>& points, vector<bool>& visit, int col, double point) {
	if (col >= points.size()) {
		answer = max(answer, point);
		return;
	}

	for (int i = 0; i < points[col].size(); i++) {
		if (!visit[i] && point * (points[col][i] / 100) > answer) {
			visit[i] = true;
			dfs(points, visit, col + 1, point * (points[col][i] / 100));
			visit[i] = false;
		}
	}
}


int main() {
	/**
	* 가장 성공률이 높은 조합을 찾는 문제
	* 
	* -- 자연어 풀이 --
	* 1. 2차원 벡터로 값을 입력 받는다
	* 2. 0, 0부터 시작하며, y축은 dfs 한칸에 + 1, x축은 dfs 중 방문 가능한 곳으로 이동시킨다
	* 3. 각 방문 표시를 남긴다
	* 4. y축의 크기가 n과 같아질경우 answer를 계산한다
	* 
	*/

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		vector<vector<double>> points(n, vector<double>(n));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> points[j][k];
			}
		}

		answer = 0;
		vector<bool> visit(n, false);
		dfs(points, visit, 0, 1.0);

		cout << "#" << i + 1 << " " << fixed << setprecision(6) << answer * 100 << "\n";
	}
}