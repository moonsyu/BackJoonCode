#include <iostream>

using namespace std;


struct Pair {
	int y;
	int x;
};

int n;
int building[100][100];
Pair guard;
int total_space;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };



int check_last_space(int y, int x) {
	int result = 0;
	for (int i = 1; guard.y + i * y < n && guard.y + i * y >= 0 && guard.x + i * x < n && guard.x + i * x >= 0; i++) {
		if (building[guard.y + i * y][guard.x + i * x]) {
			break;
		}

		result++;
	}

	return result;
}


/* 상하좌우 4방향 폭탄 처리 */
void check_four_fw() {
	for (int i = 0; i < 4; i++) {
		total_space -= check_last_space(dy[i], dx[i]);
	}
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);


	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		total_space = 0;

		cin >> n;
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				cin >> building[i][j];

				if(building[i][j] == 2) {
					guard = {i, j};
				} else if (!building[i][j]) {
					total_space++;
				}
			}
		}

		check_four_fw();

		cout << "#" << t << " " << total_space << "\n";
	}
	
}
