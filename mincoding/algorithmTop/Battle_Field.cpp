#include <iostream>

using namespace std;

int h, w;
int y, x;
char fw;
char field[20][20];


/* 전차의 시작점 탐색 */
void tank_start(int i, int j) {
	if (field[i][j] == '^' || field[i][j] == 'v' || field[i][j] == '<' || field[i][j] == '>') {
		y = i;
		x = j;
		fw = field[i][j];
	}
}


/* 포탄 발사 */
void shoot() {
	if (fw == '^') {
		for (int i = y - 1; i >= 0; i--) {
			if (field[i][x] == '*') {
				field[i][x] = '.';
				break;
			} else if (field[i][x] == '#') {
				break;
			}
		}
	} else if (fw == 'v') {
		for (int i = y + 1; i < h; i++) {
			if (field[i][x] == '*') {
				field[i][x] = '.';
				break;
			} else if (field[i][x] == '#') {
				break;
			}
		}
	} else if (fw == '<') {
		for (int i = x - 1; i >= 0; i--) {
			if (field[y][i] == '*') {
				field[y][i] = '.';
				break;
			} else if (field[y][i] == '#') {
				break;
			}
		}
	} else if (fw == '>') {
		for (int i = x + 1; i < w; i++) {
			if (field[y][i] == '*') {
				field[y][i] = '.';
				break;
			} else if (field[y][i] == '#') {
				break;
			}
		}
	}
}


/* 위로 이동 */
void up() {
	if (y - 1 >= 0 && field[y - 1][x] == '.') {
		field[y--][x] = '.';
		field[y][x] = '^';
	} else {
		field[y][x] = '^';
	}

	fw = '^';
}


/* 아래로 이동 */
void down() {
	if (y + 1 < h && field[y + 1][x] == '.') {
		field[y++][x] = '.';
		field[y][x] = 'v';
	} else {
		field[y][x] = 'v';
	}

	fw = 'v';
}


/* 왼쪽으로 이동 */
void left() {
	if (x - 1 >= 0 && field[y][x - 1] == '.') {
		field[y][x--] = '.';
		field[y][x] = '<';
	} else {
		field[y][x] = '<';
	}

	fw = '<';
}


/* 오른쪽으로 이동 */
void right() {
	if (x + 1 < w && field[y][x + 1] == '.') {
		field[y][x++] = '.';
		field[y][x] = '>';
	} else {
		field[y][x] = '>';
	}

	fw = '>';
}


/* 출력 */
void output() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << field[i][j];
		}
		cout << "\n";
	}
}

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < w; j++) {
				field[i][j] = input[j];
				tank_start(i, j);
			}
		}

		int n;
		cin >> n;
		string command;
		cin >> command;
		for (int i = 0; i < n; i++) {
			if (command[i] == 'U') {
				up();
			} else if (command[i] == 'D') {
				down();
			} else if (command[i] == 'L') {
				left();
			} else if (command[i] == 'R') {
				right();
			} else if (command[i] == 'S') {
				shoot();
			}
		}

		cout << "#" << t << " ";
		output();
	}
}
