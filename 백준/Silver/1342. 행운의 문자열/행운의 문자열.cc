#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string msg;
	long long count = 0;

	cin >> msg;
	
	sort(msg.begin(), msg.end());

	do {
		bool check = true;
		for (int i = 1; i < msg.size(); i++) {
			if (msg[i - 1] - msg[i] == 0) {
				check = false;
				break;
			}
		}
		if (check)
			count++;
	} while (next_permutation(msg.begin(), msg.end()));

	cout << count;
	
}