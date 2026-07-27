#include <iostream>


using namespace std;

int num[10];
int mul[10];


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {		
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> num[i] >> mul[i];
		}

		int answer = 0;

		bool result;
		while (true) {
			result = true;
			for (int i = 0; i < n; i++) {
				if (num[i] < answer) {
					result = false;
					num[i] += mul[i];
				} else if (num[i] > answer) {
					result = false;
					answer = num[i];
				}
			}

			if (result) {
				break;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}