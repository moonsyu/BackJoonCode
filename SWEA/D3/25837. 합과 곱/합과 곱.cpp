#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    /**
     * 두 자연수 S와 P가 주어질 때,
     * N * M = P 이고 N + M = S인 자연수 N과 M이 존재하는지 판별하라
     * 
     * -- 자연어 풀이 --
     * 1. S와 P를 입력 받는다
     * 2. P의 약수를 구한다 (for문을 통해 1부터 P까지 나누며 N, M을 구한다)
     * 3. N과 M을 더한값이 S와 같다면 cout << "Yes";와 break;
     * 4. 반복문이 끝나면 cout << "No";를 출력한다.
     * 5. 3, 4번을 구분하기 위해 answer 변수를 통해 Yes, No를 출력한다.
     * 
     * -- 추가 수정 사항 --
     * 1. P의 약수를 구할 때 sqrt(p)까지만 구한다.
     */
    
    long long tc;
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        long long s, p;
        cin >> s >> p;

        int answer = 0;
        for (int i = 1; i <= sqrt(p); i++) {
            if (p % i == 0) {
                long long n = i, m = p / i;
                if (n + m == s) {
                    answer = 1;
                    break;
                }
            }
        }

        if (!answer) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}