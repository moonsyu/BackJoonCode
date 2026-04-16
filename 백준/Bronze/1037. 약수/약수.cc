#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	long long n;
	cin >> n;

	vector<long long> divisor;
	for (long long i = 0; i < n; i++) {
		long long n; cin >> n;
		divisor.push_back(n);
	}

	sort(divisor.begin(), divisor.end());

	long long answer = divisor[n - 1];
	long long num = answer;

	while(num != 1) {
		answer += divisor[n - 1];
		num = answer;

		for (long long i = 0; i < n; i++) {
			while (num != 1 && num % divisor[i] == 0) {
				num /= divisor[i];
			}
		}

	}

	cout << answer;
}