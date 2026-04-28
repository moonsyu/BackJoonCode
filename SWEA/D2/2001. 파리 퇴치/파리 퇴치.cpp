#include <iostream>
#include <vector>

using namespace std;

int n, m;

long long calc(vector<vector<int>>& board, int x, int y) {
    int n = board.size();
    
    int answer = 0;
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + m; j++) {
            answer += board[i][j];
        }
    }

    return answer;
}


int main() {
    /**
     * N * N 크기의 2차원 배열과 M * M 크기의 2차원 배열이 주어진다
     * N * N 크기의 배열에서 M * M 크기에 해당하는 부분 배열의 값을
     * 모두 더했을 때 가장 큰 값이 얼마인지 구하라
     * 
     * 항상 N > M을 만족한다
     * 
     * -- 자연어 풀이 --
     * 1. N과 M을 입력 받는다
     * 2. N * N 크기의 2차원 배열을 입력 받는다
     * 3. 시작 좌표를 calc 함수에 넘긴다 
     *    (시작 좌표의 범위는 0 ~ N - M 이다)
     * 4. calc 함수에서 M * M 크기에 해당하는 부분 배열의 값을 모두 더해서 반환한다
     * 5. 이를 모든 시작 좌표에 대해서 반복하여 가장 큰 값을 구한다
     * 
     */

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        cin >> n >> m;

        vector<vector<int>> board(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> board[j][k];
            }
        }

        long long answer = 0;
        for (int j = 0; j <= n - m; j++) {
            for (int k = 0; k <= n - m; k++) {
                answer = max(answer, calc(board, j, k));
            }
        }

        cout << "#" << i + 1 << " " << answer << "\n";
    }
}