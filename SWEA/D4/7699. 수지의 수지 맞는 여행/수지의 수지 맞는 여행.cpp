#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
int max_answer;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

/* 명물 위치 입력 */
void input(vector<vector<char>>& board) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
}

/* 명물 위치 탐색 */
void dfs(const vector<vector<char>>& board, bool unique[], int y, int x, int cnt) {
    max_answer = max(max_answer, cnt);

    // 가지치기: 이미 모든 알파벳(26개)을 다 찾았다면 더 탐색할 필요 없음
    if (max_answer == 26) return;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
            continue;
        }

        int next_char = board[ny][nx] - 'A';
        if (!unique[next_char]) {
            unique[next_char] = true;
            dfs(board, unique, ny, nx, cnt + 1);
            unique[next_char] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> r >> c;

        vector<vector<char>> board(r, vector<char>(c));
        input(board);

        // vector<bool> 대신 일반 bool 배열 사용 (접근 속도 훨씬 빠름)
        bool unique[26] = {false};
        max_answer = 0;

        unique[board[0][0] - 'A'] = true;
        dfs(board, unique, 0, 0, 1);

        cout << "#" << t << " " << max_answer << "\n";
    }
    
    return 0;
}