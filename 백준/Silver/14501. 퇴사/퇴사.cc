#include <iostream>
#include <vector>

using namespace std;

int main() {
    /**
     * 상담 일정 계산 문제
     * 상담을 잡은 날 부터 T일 동안 상담을 진행하는데,
     * 상담을 진행하는 기간 동안 다른 상담은 불가능 하다.
     * 해당 상황에서 얻을 수 있는 최대 이익을 구하라
     * 
     * -- 자연어 풀이 --
     * 1. n일 입력 받는다
     * 2. 입력 받은의 크기를 가진 vector 변수를 선언한다
     * 3. n일 동안 상담 일정과 이익을 입력 받는다 
     *    ㄴ (t, p) 형태로 vector에 저장한다
     * 4. vector의 크기 만큼 반복문을 돌린다
     * 5. 해당 회차의 상담을 진행할 시 받는 이익과 상담 기간 동안 받을 수 있는 이익을 비교한다
     *    ㄴ for문을 사용해 현재 회차 이익 > 상담 기간 동안 받을 수 있는 이익 일 경우 진행
     * 6. 상담을 진행했을 경우 최대 이익에 상담 이익을 더한 후
     *    상담 종료 일로 현재 회차를 이동한다
     * 7. 최대 이익을 출력한다.
     * 
     * -- 추가 수정 사항 --
     * 1. 상담 기간 동안 상담이 가능한 경우에만 받을 수 있도록 한다
     * 2. 역 방향으로 순회를 돈다
     *    ㄴ 만약 상담이 불가능한 날짜의 경우 0으로 초기화
     *    ㄴ 현재 이익 < 기간 이익 일 경우 현재 이익을 0으로 초기화
     *    ㄴ 현재 이익 > 기간 이익 일 경우 기간 이익을 0으로 초기화
     *    ㄴ 순회 종료 후 다시 순회를 돌며 이익 합산
     *    ㄴ 합산한 이익 출력
     * 3. dp 방식으로 접근
     *    ㄴ 각 일자 별 최대 이익을 저장하는 dp vector 생성
     *    ㄴ 역 방향으로 순회하며 상담이 가능한지 확인
     *    ㄴ 상담이 불가능할 경우 dp[i] = dp[i + 1]
     *    ㄴ 상담이 가능할 경우 상담을 할 때와 안할 때 2가지 경우로 분기
     *    ㄴ 상담을 할 경우 dp[i] = 현재 상담 이익 + dp[i + 상담 기간]
     *    ㄴ 상담을 안할 경우 dp[i] = dp[i + 1]
     *    ㄴ dp[i] = max(상담을 할 경우, 상담을 안할 경우)
     *    ㄴ 순회 종료 후 dp[0] 출력
     */

    int n;
    cin >> n;

    vector<pair<int, int>> schedule(n);
    for (int i = 0; i < n; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }

    vector<long long> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (i + schedule[i].first > n) {
            dp[i] = dp[i + 1];
        } else {
            long long true_schedule = schedule[i].second + dp[i + schedule[i].first];
            long long false_schedule = dp[i + 1];
            dp[i] = max(true_schedule, false_schedule);
        }
    }

    cout << dp[0];
}