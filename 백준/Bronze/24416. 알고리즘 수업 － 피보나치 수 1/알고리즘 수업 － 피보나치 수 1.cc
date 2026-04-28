#include <iostream>
#include <vector>

using namespace std;


long long fibo(long long n) {
	if (n == 1 || n == 2) {
		return 1;
	}

	return fibo(n - 1) + fibo(n - 2);
}


long long fibonacci(long long n) {
	vector<long long> dp(40);
	dp[0] = dp[1] = -1;

	int count = 0;
	for (int i = 2; i < n; i++) {
		count++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return count;
}

int main() {
	int n;
	cin >> n;

	cout << fibo(n) << ' ' << fibonacci(n) << '\n';
}