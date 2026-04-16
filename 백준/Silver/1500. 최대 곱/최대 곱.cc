#include<iostream>
#include<deque>
#include<cmath>

using namespace std;

int main() {

	deque<long long> mul;

	int s, k;
	long long sum = 0;

	cin >> s >> k;

	while (mul.size() != k) {
		sum += round(s / k);
		mul.push_back(round(s / k));
	}

	int num = 0;
	while (sum < s) {
		if (mul.size() - 1 - num == -1)
			num = 0;
		mul[mul.size() - 1 - num]++;
		sum++;
		num++;
	}

	while (sum > s) {
		if (mul.size() - 1 - num == -1)
			num = 0;
		mul[mul.size() - 1 - num]--;
		sum--;
		num++;
	}

	for (int i = 1; i < k; i++)
		mul[0] *= mul[i];

	cout << mul[0];
}