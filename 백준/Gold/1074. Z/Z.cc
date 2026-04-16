#include<iostream>
#include<cmath>

using namespace std;

int r, c;
long long cnt = 0;

void repeat(long long x_start, long long x_end, long long y_start, long long y_end, long long size) {

		if (x_end - x_start + 1 != 2) {
			if (x_start <= c && (x_start + x_end) / 2 >= c && y_start <= r && (y_start + y_end) / 2 >= r) {
				repeat(x_start, (x_start + x_end) / 2, y_start, (y_start + y_end) / 2, size - 1);
			}
			else if ((x_start + x_end) / 2 + 1 <= c && x_end >= c && y_start <= r && (y_start + y_end) / 2 >= r) {
				cnt += pow(pow(2, size - 1), 2);
				repeat((x_start + x_end) / 2 + 1, x_end, y_start, (y_start + y_end) / 2, size - 1);
			}
			else if (x_start <= c && (x_start + x_end) / 2 >= c && (y_start + y_end) / 2 + 1 <= r && y_end >= r) {
				cnt += pow(pow(2, size - 1), 2) * 2;
				repeat(x_start, (x_start + x_end) / 2, (y_start + y_end) / 2 + 1, y_end, size - 1);
			}
			else {
				cnt += pow(pow(2, size - 1), 2) * 3;
				repeat((x_start + x_end) / 2 + 1, x_end, (y_start + y_end) / 2 + 1, y_end, size - 1);
			}
		}

		else {
			for (int i = y_start; i <= y_end; i++) {
				for (int j = x_start; j <= x_end; j++) {
					if (i == r && j == c) {
						cout << cnt;
					}
					cnt++;
				}
			}
		}
	
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;

	cin >> n >> r >> c;

	repeat(0, pow(2, n) - 1, 0, pow(2, n) - 1, n);
}