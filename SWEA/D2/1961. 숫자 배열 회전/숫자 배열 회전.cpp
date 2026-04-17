#include <iostream>
#include <vector>

using namespace std;

int main() {
    /** 
     * N * N 크기의 2차원 배열이 주어질 때,
     * 90도, 180도, 270도 회전한 배열을 출력하라
     * 
     * -- 자연어 풀이 --
     * 1. N을 입력 받는다
     * 2. N * N 크기의 2차원 배열을 입력 받는다
     * 3. j, k로 2차원 배열을 순회한다
     * 4. 90도는 (n - k - 1, j)를 출력하고
     * 5. 180도는 (n - j - 1, n - k - 1)을 출력하고 
     * 6. 270도는 (k, n - j - 1)를 출력한다
     */

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;

        vector<vector<int>> board(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> board[j][k];
            }
        }

        cout << "#" << i + 1 << "\n";
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << board[n - k - 1][j];
            }

            cout << " ";
            for (int k = 0; k < n; k++) {
                cout << board[n - j - 1][n - k - 1];
            }

            cout << " ";
            for (int k = 0; k < n; k++) {
                cout << board[k][n - j - 1];
            }
            
            cout << "\n";
        }
    }
}