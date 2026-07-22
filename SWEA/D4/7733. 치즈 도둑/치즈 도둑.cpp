#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 문제의 최대 N 크기 제한에 맞게 전역 배열 선언 (예: N이 최대 100일 경우 105 정도 할당)
int cheese[105][105];
bool visited[105][105];

int cheese_block(int day) {
    int result = 0;

    // 방문 배열 초기화 (동적 할당 없이 기존 메모리 덮어쓰기)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cheese[i][j] > day && !visited[i][j]) {
                result++;

                queue<pair<int, int>> que;
                que.push({ i, j });
                visited[i][j] = true;

                while (!que.empty()) {
                    auto [x, y] = que.front();
                    que.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        }

                        if (cheese[nx][ny] > day && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            que.push({ nx, ny });
                        }
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;

        int max_day = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cheese[i][j];
                max_day = max(max_day, cheese[i][j]);
            }
        }

        int answer = -1;
        for (int i = 0; i <= max_day; i++) {
            answer = max(answer, cheese_block(i));
        }

        cout << "#" << t << " " << answer << "\n";
    }
}