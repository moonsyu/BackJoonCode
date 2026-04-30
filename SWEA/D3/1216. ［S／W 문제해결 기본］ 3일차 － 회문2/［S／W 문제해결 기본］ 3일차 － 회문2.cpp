#include <iostream>
#include <algorithm>
#include <vector>

#define tc 10
#define square_size 100

using namespace std;

/* 가로행 회문 길이 탐색 */
long long row_palindrome(vector<vector<string>>& square) {
	long long max_length = 1;
	for (int i = 0; i < square_size; i++) {
		// 회문의 최대 길이보다 낮은 길이의 문자열 탐색 제한
		for (int j = 0; j < square_size; j++) {
			for (int k = j + max_length; k < square_size; k++) {

				// 회문 검사
				bool check = true;
				for (int l = 0; l < (k - j + 1) / 2; l++) {
					if (square[i][j + l] != square[i][k - l]) {
						check = false;
						break;
					}
				}

				// 회문 길이 갱신
				if (check) {
					max_length = max(max_length, (long long)(k - j + 1));
				}
			}
		}
	}

	return max_length;
}


/* 세로열 회문 길이 탐색 */
long long col_palindrome(vector<vector<string>>& square) {
	long long max_length = 1;
	for (int i = 0; i < square_size; i++) {
		// 회문의 최대 길이보다 낮은 길이의 문자열 탐색 제한
		for (int j = 0; j < square_size; j++) {
			for (int k = j + max_length; k < square_size; k++) {

				// 회문 검사
				bool check = true;
				for (int l = 0; l < (k - j + 1) / 2; l++) {
					if (square[j + l][i] != square[k - l][i]) {
						check = false;
						break;
					}
				}

				// 회문 길이 갱신
				if (check) {
					max_length = max(max_length, (long long)(k - j + 1));
				}
			}
		}
	}

	return max_length;
}


int main() {
	
	for (int i = 0; i < tc; i++) {
		int t;
		cin >> t;

		vector<vector<string>> square(square_size, vector<string>(square_size));
		for (int j = 0; j < square_size; j++) {
			string text;
			cin >> text;

			for (int k = 0; k < text.size(); k++) {
				square[j][k] = text[k];
			}
		}

		long long answer = 0;
		answer = max(row_palindrome(square), col_palindrome(square));

		cout << "#" << t << " " << answer << "\n";
	}
}