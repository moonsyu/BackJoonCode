#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string people;
		cin >> people;

		long long answer = 0; // 고용한 사람 수
		long long total_clap_cnt = 0; // 현재까지 박수 친 인원 수
		for (int i = 0; i < people.size(); i++) {
			int clap_cnt = i; // 가독성 고려해서 새로운 변수 선언

			// 사람을 고용해야 할 경우
			if (clap_cnt > total_clap_cnt) {
				// 현재 고용해야 하는 사람 수
				int add_clap = clap_cnt - total_clap_cnt;

				// 고용한 사람 및 박수 친 인원 수 갱신
				answer += add_clap;
				total_clap_cnt += add_clap;
			}

			// 현재 라운드에 박수 친 인원 갱신
			total_clap_cnt += (people[i] - '0');
		}

		cout << "#" << t << " " << answer << endl;
	}
}