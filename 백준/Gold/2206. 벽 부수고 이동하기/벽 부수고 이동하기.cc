
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    vector<vector<array<int, 2>>> dist(n, vector<array<int, 2>>(m, {0, 0}));
    queue<array<int, 3>> q;

    dist[0][0][0] = 1;
    q.push(array<int, 3>{0, 0, 0});

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int r = cur[0];
        int c = cur[1];
        int broken = cur[2];

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (board[nr][nc] == '0' && dist[nr][nc][broken] == 0) {
                dist[nr][nc][broken] = dist[r][c][broken] + 1;
                q.push(array<int, 3>{nr, nc, broken});
            }

            if (board[nr][nc] == '1' && broken == 0 && dist[nr][nc][1] == 0) {
                dist[nr][nc][1] = dist[r][c][0] + 1;
                q.push(array<int, 3>{nr, nc, 1});
            }
        }
    }

    int a = dist[n - 1][m - 1][0];
    int b = dist[n - 1][m - 1][1];

    if (a == 0 && b == 0) {
        cout << -1;
    } else if (a == 0) {
        cout << b;
    } else if (b == 0) {
        cout << a;
    } else {
        cout << min(a, b);
    }

    return 0;
}