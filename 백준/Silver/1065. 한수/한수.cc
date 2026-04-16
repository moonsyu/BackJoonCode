#include<iostream>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int N;
	cin >> N;

	if (N < 100)
		cout << N;
	else {
		int count = 99;
		string n;

		for (int i = 111; i <= N; i++) {
			n = to_string(i);
			int check = n[0] - n[1];
			bool tf = true;
			for (int j = 1; j < n.size(); j++) {
				if (check != n[j - 1] - n[j]) {
					tf = !tf;
					break;
				}
			}
			if (tf)
				count++;
		}
		cout << count;
	}
}