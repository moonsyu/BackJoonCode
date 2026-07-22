#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cheese[10005];
int visited[10005];
int day_list[105];

int que[10005];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cheese_block(int day, int t) {
    int result = 0;
    int mark = (t * 105) + day;

    for (int i = 0; i < n * n; i++) {
        if (cheese[i] > day && visited[i] != mark) {
            result++;

            int head = 0;
            int tail = 0;

            que[tail++] = i;
            visited[i] = mark;

            while (head < tail) {
                int cur = que[head++];

                int cy = cur / n;
                int cx = cur % n;

                for (int d = 0; d < 4; d++) {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        continue;
                    }

                    int next_idx = ny * n + nx;
                    if (cheese[next_idx] > day && visited[next_idx] != mark) {
                        visited[next_idx] = mark;
                        que[tail++] = next_idx;
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

        for (int i = 0; i < n * n; i++) {
            cin >> cheese[i];
            day_list[cheese[i]] = t;
        }

        int answer = 1;
        for (int day = 1; day < 100; day++) {
            if (day_list[day] == t) {
                answer = max(answer, cheese_block(day, t));
            }
        }

        cout << "#" << t << " " << answer << "\n";
    }
}