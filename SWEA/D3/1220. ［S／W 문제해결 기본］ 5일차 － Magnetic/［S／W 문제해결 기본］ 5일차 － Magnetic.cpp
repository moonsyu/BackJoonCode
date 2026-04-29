#include <iostream>
#include <vector>

#define tc 10

using namespace std;

int main() {
	
	for (int i = 0; i < tc; i++) {
		int area_size;
		cin >> area_size;

		vector<vector<int>> area(area_size, vector<int>(area_size));
		for (int j = 0; j < area_size; j++) {
			for (int k = 0; k < area_size; k++) {
				cin >> area[j][k];
			}
		}
		
		int last_magnetic;
		long long answer = 0;
		for (int y = 0; y < area_size; y++) {
			last_magnetic = 0;
			for (int x = 0; x < area_size; x++) {
				// N극이 나올 경우 스택에 저장
				if (area[x][y] == 1) {
					last_magnetic = 1;
				} 
				// S극이 나올 경우 stack 확인
				else if (area[x][y] == 2 && last_magnetic == 1) {
					last_magnetic = 0;
					answer++;
				} 
			}
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}
}