#include <iostream>
#include <vector>

using namespace std;


void calc(vector<vector<string>>& tile, int y, int x) {
	bool check = true;
	for (int i = y; i < y + 2 && check; i++) {
		for (int j = x; j < x + 2 && check; j++) {
			if (tile[i][j] != "#") {
				check = false;
			}
		}
	}

	if (check) {
		for (int i = y; i < y + 2; i++) {
			for (int j = x; j < x + 2; j++) {
				tile[i][j] = ".";
			}
		}
	}
}

string tile_check(vector<vector<string>>& tile) {
	for (int i = 0; i < tile.size(); i++) {
		for (int j = 0; j < tile[i].size(); j++) {
			if (tile[i][j] == "#") {
				return "NO";
			}
		}
	}

	return "YES";
}

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n >> m;

		vector<vector<string>> tile(n, vector<string>(m));
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < m; j++) {
				tile[i][j] = temp[j];
			}
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				calc(tile, i, j);
			}
		}

		cout << "#" << i + 1 << " " << tile_check(tile) << endl;
	}
}