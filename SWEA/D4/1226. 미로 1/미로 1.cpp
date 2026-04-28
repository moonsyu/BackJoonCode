#include <iostream>
#include <vector>

using namespace std;


bool found = false;
vector<vector<int>> maze(16, vector<int>(16));


void calc(vector<vector<bool>>& visit, int x, int y) {
	if (maze[x][y] == 1) {
		return;
	}

	if (found || maze[x][y] == 3) {
		found = true;
		return;
	}
	
	visit[x][y] = false;
	if (x - 1 >= 0 && visit[x - 1][y]) {
		calc(visit, x - 1, y);
	}

	if (x + 1 < 16 && visit[x + 1][y]) {
		calc(visit, x + 1, y);
	}

	if (y - 1 >= 0 && visit[x][y - 1]) {
		calc(visit, x, y - 1);
	}

	if (y + 1 < 16 && visit[x][y + 1]) {
		calc(visit, x, y + 1);
	}
}


int main() {

	/**
	* 미로에서 도착지까지 갈 수 있는지 여부를 출력하라
	* 시작점: 2 (좌표는 1,1)
	* 도착점 : ?
	* 이동 가능한 길: 0
	* 벽: 1
	* 
	* 테스트케이스는 10개 고정
	* 미로 크기는 16* 16 고정
	* 
	* -- 자연어 풀이 --
	* 1. 미로의 크기 만큼 2차원 vector 선언
	* 2. 미로의 정보를 입력받아 vector에 저장
	* 3. 시작 좌표 1,1 입력
	* 4. 상하좌우 중 길인 곳으로 이동하며 도착점에 도달할 때까지 반복
	* 5. 도착점에 도달하면 1 출력, 도달하지 못하면 0 출력
	* 
	*/

	int tc = 10;
	int tc_num;
	for (int i = 0; i < tc; i++) {
		cin >> tc_num;
		for (int j = 0; j < 16; j++) {
			long long tmp;
			cin >> tmp;

			int k = 0;
			while (tmp) {
				maze[j][15 - k++] = tmp % 10;
				tmp /= 10;
			}
				
		}

		found = false;
		vector<vector<bool>> visit(16, vector<bool>(16, true));
		calc(visit, 1, 1);

		cout << "#" << tc_num << " " << (found ? 1 : 0) << endl;
	}
}