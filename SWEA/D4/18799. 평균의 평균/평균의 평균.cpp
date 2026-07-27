#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {		
		int n;
		cin >> n;

		long double calc = 0;
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			
			calc += input;
		}

		cout << "#" << t << " " << setprecision(20) << calc / n<< "\n";
	}
}