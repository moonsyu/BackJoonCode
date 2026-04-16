#include<iostream>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string a;
	string b;

	cin >> a >> b;

	int count, min = 50;
	for (int i = 0; i < b.size() - a.size() + 1; i++) {
		count = 0;
		for (int j = 0; j < a.size(); j++) {
			if (b[i + j] != a[j])
				count++;
		}

		if (min > count)
			min = count;
	}

	cout << min;
}