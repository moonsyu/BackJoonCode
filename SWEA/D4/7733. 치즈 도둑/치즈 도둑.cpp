#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int cheese[100][100];
int visited[100][100];

queue<pair<int, int>> que;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cheese_block(int day) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cheese[i][j] > day && visited[i][j] != day) {
                result++;

                que.push({ i, j });
                visited[i][j] = day;

                while (!que.empty()) {
                    auto [x, y] = que.front();
                    que.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        }

                        if (cheese[nx][ny] > day && visited[nx][ny] != day) {
                            visited[nx][ny] = day;
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
        memset(visited, 0, sizeof(visited));

        cin >> n;

        int max_day = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cheese[i][j];
				max_day = max(max_day, cheese[i][j]);
            }
        }

        int answer = 1;
        for (int i = 1; i <= max_day; i++) {
            answer = max(answer, cheese_block(i));
        }

        cout << "#" << t << " " << answer << endl;
    }
}