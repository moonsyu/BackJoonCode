#include <iostream>
#include <vector>

using namespace std;


/* 맵 입력 및 탱크 좌표 반환 */
pair<int, int> input_map(vector<vector<string>>& map) {
	int h = map.size();
	int m = map[0].size();
	
	pair<int, int> tank;
	for (int i = 0; i < h; i++) {
		string input_row;
		cin >> input_row;

		for (int j = 0; j < m; j++) {
			map[i][j] = input_row[j];

			// 탱크 좌표 저장
			if (map[i][j] == "^" || map[i][j] == "v" || map[i][j] == "<" || map[i][j] == ">") {
				tank = make_pair(i, j);
			}
		}
	}

	return tank;
}


/* 포탄 발사 */
void shot(vector<vector<string>>& map, pair<int, int>& tank) {
	int x = tank.first;
	int y = tank.second;

	// 탱크 방향에 따라 포탄 발사
	if (map[x][y] == "^") {
		for (int i = x - 1; i >= 0; i--) {
			// 강철 벽에 막힘
			if (map[i][y] == "#") { 
				break; 
			} else if (map[i][y] == "*") { // 벽돌 벽 파괴
				map[i][y] = ".";
				break;
			}
		}
	} else if (map[x][y] == "v") {
		for (int i = x + 1; i < map.size(); i++) {
			// 강철 벽에 막힘
			if (map[i][y] == "#") { 
				break; 
			} else if (map[i][y] == "*") { // 벽돌 벽 파괴
				map[i][y] = "."; 
				break;
			}
		}
	} else if (map[x][y] == "<") {
		for (int j = y - 1; j >= 0; j--) {
			// 강철 벽에 막힘
			if (map[x][j] == "#") {
				break; 
			} else if (map[x][j] == "*") { // 벽돌 벽 파괴
				map[x][j] = "."; 
				break;
			}
		}
	} else if (map[x][y] == ">") {
		for (int j = y + 1; j < map[0].size(); j++) {
			// 강철 벽에 막힘
			if (map[x][j] == "#") { 
				break; 
			} else if (map[x][j] == "*") { // 벽돌 벽 파괴
				map[x][j] = "."; 
				break;
			}
		}
	}
}


/* 탱크 이동 */
void move(vector<vector<string>>& map, pair<int, int>& tank, char command) {
	int x = tank.first;
	int y = tank.second;

	if (command == 'U') {
		map[x][y] = "^";

		if (x > 0 && map[x - 1][y] == ".") {
			map[x][y] = ".";
			x--;
			map[x][y] = "^";
			tank = make_pair(x, y);
		}
	} else if (command == 'R') {
		map[x][y] = ">";

		if (y < map[0].size() - 1 && map[x][y + 1] == ".") {
			map[x][y] = ".";
			y++;
			map[x][y] = ">";
			tank = make_pair(x, y);
		}
	} else if (command == 'D') {
		map[x][y] = "v";

		if (x < map.size() - 1 && map[x + 1][y] == ".") {
			map[x][y] = ".";
			x++;
			map[x][y] = "v";
			tank = make_pair(x, y);
		}
	} else if (command == 'L') {
		map[x][y] = "<";

		if (y > 0 && map[x][y - 1] == ".") {
			map[x][y] = ".";
			y--;
			map[x][y] = "<";
			tank = make_pair(x, y);
		}
	}
}


/* 맵 출력 */
void output_map(vector<vector<string>>& map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}


int main() {
	
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int h, m;
		cin >> h >> m;

		// 탱크 좌표
		pair<int, int> tank;

		// 맵 입력
		vector<vector<string>> map(h, vector<string>(m));
		tank = input_map(map);

		int n;
		cin >> n;

		string command;
		cin >> command;

		//cout << "now\n";
		//output_map(map);
		//cout << "\n";

		// 커맨드 실행
		for (int j = 0; j < command.length(); j++) {
			if (command[j] == 'S') {
				shot(map, tank);
			} else {
				move(map, tank, command[j]);
			}

			//cout << j + 1 << " turn\n";
			//cout << "command: " << command[j] << "\n";
			//output_map(map);
			//cout << "\n";
		}

		// 결과 출력
		cout << "#" << i + 1 << " ";
		output_map(map);
	}
}