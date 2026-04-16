#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int answer = 999999;

void min_count(deque<int> &save, long long n) {
	if (save.size() < answer) {
		if (n == 1) {
			if (answer > save.size()) {
				answer = save.size();
			}
		}
		else {
			if (n % 3 == 0) {
				save.push_back(3);
				min_count(save, n / 3);
				save.pop_back();
			}
			if (n % 2 == 0) {
				save.push_back(2);
				min_count(save, n / 2);
				save.pop_back();
			}

			save.push_back(1);
			min_count(save, n - 1);
			save.pop_back();

		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	long long n;
	deque<int> save;
	cin >> n;

	min_count(save, n);
	cout << answer;
}