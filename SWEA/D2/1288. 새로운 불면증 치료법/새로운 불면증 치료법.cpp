#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		int check = 0;
		vector<bool> num(10, true);
		
		long long answer = 0;
		while (check != 10) {
			long long temp = ++answer * n;
			while (temp > 0) {
				int digit = temp % 10;
				if (num[digit]) {
					num[digit] = false;
					check++;
				}

				temp /= 10;
			}
		}

		cout << "#" << i + 1 << " " << answer * n << endl;
	}
}