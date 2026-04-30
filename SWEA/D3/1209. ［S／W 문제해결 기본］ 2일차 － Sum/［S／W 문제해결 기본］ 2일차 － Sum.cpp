#include <iostream>
#include <queue>

#define tc 10
#define square_size 100

using namespace std;

/* 가로행 계산 */
long long row_calc(vector<vector<int>>& square) {
	long long answer = 0;
	for (int i = 0; i < square_size; i++) {
		long long sum = 0;
		for (int j = 0; j < square_size; j++) {
			sum += square[i][j];
		}
		answer = max(answer, sum);
	}

	return answer;
}


/* 세로열 계산 */
long long col_calc(vector<vector<int>>& square) {
	long long answer = 0;
	for (int i = 0; i < square_size; i++) {
		long long sum = 0;
		for (int j = 0; j < square_size; j++) {
			sum += square[j][i];
		}
		answer = max(answer, sum);
	}

	return answer;
}


/* 대각선 계산 */
long long diag_calc(vector<vector<int>>& square) {
	long long sum1 = 0, sum2 = 0;
	for (int i = 0; i < square_size; i++) {
		sum1 += square[i][i];
		sum2 += square[i][square_size - 1 - i];
	}

	return max(sum1, sum2);
}


int main() {

	for (int i = 0; i < tc; i++) {
		int t;
		cin >> t;

		vector<vector<int>> square(square_size, vector<int>(square_size));
		for (int j = 0; j < square_size; j++) {
			for (int k = 0; k < square_size; k++) {
				cin >> square[j][k];
			}
		}

		long long answer = 0;
		answer = max(answer, row_calc(square));
		answer = max(answer, col_calc(square));
		answer = max(answer, diag_calc(square));

		cout << "#" << t << " " << answer << "\n";
	}
}