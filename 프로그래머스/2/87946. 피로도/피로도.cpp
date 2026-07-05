#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -1;
void combination(vector<vector<int>> &dungeons, vector<bool> &visit, int k, int cnt) {
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (dungeons[i][0] <= k && visit[i]) {
            visit[i] = false;
            combination(dungeons, visit, k - dungeons[i][1], cnt + 1);
            visit[i] = true;
        }
    }
    
    answer = max(answer, cnt);
}


int solution(int k, vector<vector<int>> dungeons) {
    
    vector<bool> visit(dungeons.size(), true);
    combination(dungeons, visit, k, 0);
    
    return answer;
}