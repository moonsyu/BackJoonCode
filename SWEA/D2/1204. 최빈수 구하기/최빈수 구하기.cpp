#include <iostream>
#include <vector>

#define MAX_SCORE 100
#define STUDENT_CNT 1000

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int tn;
		cin >> tn;

		vector<long long> score(MAX_SCORE + 1, 0);
		for (int j = 0; j < STUDENT_CNT; j++) {
			int num;
			cin >> num;

			score[num]++;
		}

		int answer;
		int people_cnt = 0;
		for (int j = 0; j <= MAX_SCORE; j++) {
			if (people_cnt <= score[j]) {
				people_cnt = score[j];
				answer = j;
			}
		}

		cout << "#" << tn << " " << answer << "\n";
	}
}