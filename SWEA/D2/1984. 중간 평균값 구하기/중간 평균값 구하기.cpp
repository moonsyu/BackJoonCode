#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		vector<double> v(10);
		for (int j = 0; j < 10; j++) {
			cin >> v[j];
		}

		sort(v.begin(), v.end());

		double answer = 0;
		for (int j = 1; j < 9; j++) {
			answer += v[j];
		}

		answer /= 8;

		cout << "#" << i + 1 << " " << (int)(answer + 0.5) << endl;
	}
}