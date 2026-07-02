#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

/* 주변 8방향 폭탄 찾기 */
int find_boom(vector<vector<char>>& board, int x, int y) {
    
    int find_cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
            continue;
        }

        if (board[nx][ny] == '*') {
            find_cnt++;
        }
    }

    return find_cnt;
}


/* 추가 탐색 */
void dfs(vector<vector<char>>& board, int x, int y) {
    
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) {
            continue;
        }

        if (board[nx][ny] == '.') {
            int boom_cnt = find_boom(board, nx, ny);
            board[nx][ny] = boom_cnt + '0';

            if (!boom_cnt) {
                dfs(board, nx, ny);
            }
        }
    }
}


int main() {
    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        vector<vector<char>> board(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            string input;
            cin >> input;

            for (int j = 0; j < n; j++) {
                board[i][j] = input[j];
            }
        }

        int answer = 0;
        // 주변에 폭탄이 없는 칸 우선 탐색
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    // 주변에 폭탄이 없을 경우
                    if (!find_boom(board, i, j)) {
                        answer++;
                        board[i][j] = '0';
                        
                        dfs(board, i, j);
                    }
                }
            }
        }
        
        // 이후 남은 칸 탐색
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    answer++;
                    // 주변 폭탄 개수 찾기
                    board[i][j] = find_boom(board, i, j) + '0';
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
}