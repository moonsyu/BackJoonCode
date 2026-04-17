#include <iostream>
#include <vector>

using namespace std;

long long calc(vector<vector<int>>& board, int word_len, int j, int k) {
    int n = board.size();
    
    int answer = 0;
    // 가로 방향 검사
    for (j = 0; j < n; j++) {
        int count = 0;
        int prev = board[j][0];

        for (int k = 0; k < n; k++) {
            if (board[j][k] == 1) {
                count++;
            } else {
                if (count == word_len) {
                    answer++;
                }
                count = 0;
            }
        }

        if (count == word_len) {
            answer++;
        }
    }

    // 세로 방향 검사
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int k = 0; k < n; k++) {
            if (board[k][j] == 1) {
                count++;
            } else {
                if (count == word_len) {
                    answer++;
                }
                count = 0;
            }
        }

        if (count == word_len) {
            answer++;
        }
    }

    return answer;
}

int main() {
    /**
     * N * N 크기의 2차원 배열과 단어의 길이 K가 주어질 때,
     * 단어가 들어갈 수 있는 위치의 개수를 구하라
     * 
     * -- 자연어 풀이 --
     * 1. N과 K를 입력 받는다
     * 2. N * N 크기의 2차원 배열을 입력 받는다
     * 3. (0,0) 부터 (n-1, n-1)까지 2차원 배열을 순회한다
     * 4. 해당 위치로 부터 오른쪽과 아래로 K 길이 만큼 비어 있는지 확인한다.
     * 5. 비어있을 경우 한칸 더 확인하여 해당 칸이 비어 있는지 확인한다
     * 6. 해당 칸이 비어있지 않을 경우 answer에 1을 더한다
     * 7. 순회 종료 후 answer를 출력한다. 
     * 
     * -- 추가 수정 사항 --
     * 1. 각 칸을 순회하지 않고 각 행과 열에서 연속된 칸의 개수를 구한다
     *    ㄴ 연속된 칸의 개수가 k일 경우 answer에 1을 더한다.
     */

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int n, word_len;
        cin >> n >> word_len;

        vector<vector<int>> board(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> board[j][k];
            }
        }

        int answer = calc(board, word_len, 0, 0);

        cout << "#" << i + 1 << " " << answer << "\n";
    }
}