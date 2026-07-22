#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int cheese[100][100];
int visited[100][100][100];
int day_list[101];

queue<pair<int, int>> que;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cheese_block(int day, int t) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cheese[i][j] > day && visited[i][j][t] != day) {
                result++;

                que.push({ i, j });
                visited[i][j][t] = day;

                while (!que.empty()) {
                    auto [x, y] = que.front();
                    que.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        }

                        if (cheese[nx][ny] > day && visited[nx][ny][t] != day) {
                            visited[nx][ny][t] = day;
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
	cout.tie(nullptr);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {

        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cheese[i][j];
                day_list[cheese[i][j]] = t;
            }
        }

        int answer = 1;
        for (int day = 1; day < 100; day++) {
			if (day_list[day] == t) {
                answer = max(answer, cheese_block(day, t));
			}
        }

        cout << "#" << t << " " << answer << endl;
    }
}