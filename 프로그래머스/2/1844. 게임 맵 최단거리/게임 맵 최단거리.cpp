#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


/* 도착지 주변이 막혀있는지 확인 */
bool goal_around(vector<vector<int>> &maps, int n, int m) {
    int dx[] = {-1, 0};
    int dy[] = {0, -1};
    
    bool result = false;
    for (int i = 0; i < 2; i++) {
        int nx = m - 1 + dx[i];
        int ny = n - 1 + dy[i];
        
        if (nx < 0 || ny < 0) {
            continue;
        }
        
        if (maps[ny][nx]) {
            result = true;
            break;
        }
    }
    
    return result;
}


/* 도착지 탐색 */
int bfs(vector<vector<int>> &maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    // 도착 가능 여부 확인
    if (!goal_around(maps, n, m)) {
        return -1;
    }
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    queue<int> que;
    que.push(0);
    maps[0][0] = 2;
    
    // 방문 체크
    while (!que.empty()) {
        int y = que.front() / m;
        int x = que.front() % m;
        que.pop();
        
        // 4방향 이동 경로 탐색
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 도착 시 종료
            if (ny == n - 1 && nx == m - 1) {
                return maps[y][x];
            }
            
            // 범위 체크
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }
            
            // 방문 가능 && 이동 가능
            if (maps[ny][nx] == 1) {
                maps[ny][nx] = maps[y][x] + 1;
                que.push(ny * m + nx);
            }
        }
    }
    
    return -1;
}


int solution(vector<vector<int>> maps)
{
    int answer = -1;
    
    answer = bfs(maps);
    return answer;
}