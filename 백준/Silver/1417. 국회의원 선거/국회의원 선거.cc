#include <iostream>
#include <queue>

using namespace std;

int main() {

    /** 
     * 국회의원 선거
     * https://www.acmicpc.net/problem/1417
     * 
     * 
     * 현재 투표 현황이 주어졌을 때,
     * 기호 1번이 당선될 수 있도록 다른 후보자들의 투표 수를 조작하려 한다
     * 당선 되기 위해 가장 적은 조작 횟수를 구하라
     * 
     * -- 자연어 풀이 --
     * 1. n을 입력 받는다
     * 2. 1번은 now에 저장한다
     * 3. 2번 부터 n번까지 pq에 저장한다
     * 4. pq의 top이 now보다 크거나 같다면 top--, now++, answer++
     * 5. 4번을 top이 now보다 작아질 때 까지 반복한다
     * 
     */

    int n;
    cin >> n;

    int now;
    cin >> now;

    int answer = 0;
    priority_queue<int> pq;
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    while (!pq.empty() && pq.top() >= now) {
        pq.push(pq.top() - 1);
        pq.pop();

        now++;
        answer++;
    }

    cout << answer;
}