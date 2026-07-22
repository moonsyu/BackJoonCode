#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int cheese[10005];
int visited[10005];
int day_list[105];
queue<int> que; 

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cheese_block(int day, int t) {
    int result = 0;
    // 테스트 케이스 번호(t)와 day를 조합하여 매번 고유한 마커 생성 (memset 대체)
    int mark = (t * 105) + day;

    for (int i = 0; i < n * n; i++) {
        if (cheese[i] > day && visited[i] != mark) {
            result++;

            que.push(i);
            visited[i] = mark;

            while (!que.empty()) {
                int cur = que.front();
                que.pop();

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
                        que.push(next_idx);
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