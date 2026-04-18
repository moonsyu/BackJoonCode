#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    /**
     * 최대 힙
     * https://www.acmicpc.net/problem/11279
     * 
     * x가 주어졌을 때 
     * 0이 주어지면 가장 큰 값을 출력 및 배열에서 제거 하고,
     * 0이 아닌 값이 주어지면 배열에 추가하는 문제
     * 
     * -- 자연어 풀이 --
     * 1. n을 입력 받는다
     * 2. n번 반복하며 값을 받을 때 0이 주어지면 큰 값을 출력 및 제거하고,
     *    0이 아닌 값이 주어지면 배열에 추가한다
     * 
     */


    cin.tie(NULL);
    ios::sync_with_stdio(false);    
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}