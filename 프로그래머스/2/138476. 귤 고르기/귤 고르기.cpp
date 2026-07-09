#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    // 크기별 정렬
    sort(tangerine.begin(), tangerine.end());
    
    // 크기별 개수 저장
    int num = tangerine[0];
    int cnt = 0;
    vector<pair<int, int>> tang_cnt; // {개수, 크기}
    for(int i = 0; i < tangerine.size(); i++) {
        if (num == tangerine[i]) {
            cnt++;
        } else {
            tang_cnt.push_back({cnt, num});
            num = tangerine[i];
            cnt = 1;
        }
    }
    
    tang_cnt.push_back({cnt, num});
    
    // 크기 기준 내림차순 정렬
    sort(tang_cnt.rbegin(), tang_cnt.rend());
    
    // 귤 선택
    for (int i = 0; i < tang_cnt.size() && k > 0; i++) {
        k-= tang_cnt[i].first;
        answer++;
    }
    
    return answer;
}