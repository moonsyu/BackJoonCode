#include <iostream>
#include <string>


using namespace std;

string answer = "";

void make_string(int a, int b, int c, int d, string& now) {

	if (!answer.empty()) {
		return;
	}

	// 모두 다 사용했을 경우
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		answer = now;
		return;
	}

	int last_num = now[now.size() - 1] - '0';
	if (last_num) {
		if (c > 0) {
			make_string(a, b, c - 1, d, now + "0");
			now.pop_back();
		}

		if (d > 0) {
			make_string(a, b, c, d - 1, now + "1");
			now.pop_back();
		}
	}
	else {
		if (a > 0) {
			make_string(a - 1, b, c, d, now + "0");
			now.pop_back();
		}

		if (b > 0) {
			make_string(a, b - 1, c, d, now + "1");
			now.pop_back();
		}
	}
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		answer = "";
		string now = "";
		make_string(a, b, c, d, now + "0");
		make_string(a, b, c, d, now + "1");

		cout << "#" << t << " " << (answer.empty() ? "impossible" : answer) << "\n";
	}
}