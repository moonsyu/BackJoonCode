#include<iostream>
#include<deque>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int N, answer, P;

	cin >> N >> answer >> P;

	deque<int> point;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		point.push_back(n);
	}

	if (point.empty() == true)
		cout << 1;
	else {
		int count = 1, index = 0;
		while (index < N && index < P) {
			if (point[index] > answer)
				count++;
			else if (point[index] < answer)
				break;
			index++;
		}
		if (index == P)
			cout << -1;
		else
			cout << count;
	}

}