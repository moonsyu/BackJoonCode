#include <iostream>
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

		string answer = "";
		if (n == 1) {
			answer = "0";
		}
		else if (n % 2){
			answer += "4";
			for (int i = 0; i < n / 2; i++) {
				answer += "8";
			}
		}
		else {
			for (int i = 0; i < n / 2; i++) {
				answer += "8";
			}
		}
	
		cout << answer << endl;
	}
}