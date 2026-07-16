#include <iostream>
#include <vector>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        int city, d;
        cin >> city >> d;

        // 차원 관문 위치 기록
        vector<int> exist(city, 0);
        for (int i = 0; i < city; i++) {
            cin >> exist[i];
        }

        // 시작 위치에 차원 관문이 없는 경우, answer 1 증가
        int answer = 0;
        if (!exist[0]) {
            answer++;
        }

        // 차원 관문 설치 계산
        int last_city = 0;
        for (int i = 1; i < city;) {

            // 차원 관문의 최대 이동 거리 내에 
            // 또 다른 차원 관문이 존재하는지 확인
            bool can_mv = true;
            for (int j = i; j < i + d && j < city; j++) {
                // 차원 관문 존재 시
                // 해당 차원 관문으로 이동
                if (exist[j] == 1) {
                    last_city = j;
                    i = ++j;
                    can_mv = false;
                    break;
                }
            }

            // 경로 내에 차원 관문이 존재하지 않는 경우,
            // 차원 관문 설치 후 이동
            if (can_mv) {
                answer++;
                i += d;
            }
        }

        cout << "#" << t << " " << answer << endl;
    }
}