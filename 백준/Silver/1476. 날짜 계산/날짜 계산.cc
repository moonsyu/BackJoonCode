#include <iostream>

using namespace std;

int main() {
    /**
     * 날짜 범위가 정해진 E, S, M 이라는 세 수가 있다.
     * 각각의 변수는 1부터 시작해서 E는 15, S는 28, M은 19까지의 범위를 가진다.
     * 만약 범위를 넘어갈 경우 다시 1로 돌아갈 때 
     * 현재 날짜를 구하는 프로그램을 작성하라
     * 
     * -- 자연어 풀이 --
     * 1. e, s, m을 입력받는다
     * 2. for 문을 돌며 e, s, m이 모두 같을 때 까지 answer에 1씩 더한다
     * 3. e, s, m이 범위를 넘어갈 때 마다 1로 초기화 한다.
     */

    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.tie(0);

    int e, s, m;
    cin >> e >> s >> m;

    int answer = 1;
    while (((answer % 15 ? answer % 15 : 15) != e) 
        || ((answer % 28 ? answer % 28 : 28) != s)
        || ((answer % 19 ? answer % 19 : 19) != m)) {

        answer++;
    }

    cout << answer;
}