#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	bool check = true;
	deque<deque<bool>> chess(6, deque<bool>(6, false));
	deque<string> loc;

	for (int i = 0; i < 36; i++) {
		string msg;
		cin >> msg;
		loc.push_back(msg);
	}

	chess[loc[0][0] - 65][loc[0][1] - '1'] = true;

	for (int i = 1; i < 36; i++) {
		int loc_x = abs(loc[i - 1][0] - loc[i][0]); // 이동한 x좌표의 간격
		int loc_y = abs(loc[i - 1][1] - loc[i][1]); // 이동한 y좌표의 간격

		if (loc_x == 0 || loc_y == 0 || loc_x + loc_y != 3) {
			check = false;
			break;
		}
		else if (chess[loc[i][0] - 65][loc[i][1] - '1'] == true) {
			check = false;
			break;
		}

		chess[loc[i][0] - 65][loc[i][1] - '1'] = true; // 현재 좌표를 지나간걸 표시
	}

	// 나이트가 출발점으로 돌아왔는지 확인
	int arrive_x = abs(loc[0][0] - loc[loc.size() - 1][0]); // 첫번째 x좌표와 마지막 x좌표의 간격
	int arrive_y = abs(loc[0][1] - loc[loc.size() - 1][1]); // 첫번째 y좌표와 마지막 y좌표의 간격

	if (arrive_x == 0 || arrive_y == 0 || arrive_x + arrive_y != 3)
		check = false;

	if (check)
		cout << "Valid";
	else
		cout << "Invalid";
}