#include <iostream>
#include <queue>

#define tc 10
#define square_size 100

using namespace std;

vector<int> dx = { 1, 0, 1 };
vector<int> dy = { 0, 1, 1 };



int main() {

	for (int i = 0; i < tc; i++) {
		int t;
		cin >> t;

		vector<vector<int>> square(square_size, vector<int>(square_size));
		for (int j = 0; j < square_size; j++) {
			for (int k = 0; k < square_size; k++) {
				cin >> square[j][k];
			}
		}

		


	}
}