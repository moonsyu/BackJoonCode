#include <iostream>


using namespace std;

int n, m;
bool area[1000][1000];

int dx[4] = { 0, 2, 0, -2 };
int dy[4] = { 2, 0, -2, 0 };


void reset_area() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			area[i][j] = true;
		}
	}
}


void four_dir(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			area[nx][ny] = false;
		}
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;

		reset_area();

		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {	
				if (area[i][j]) {
					answer++;
					area[i][j] = false;
					four_dir(i, j);
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}