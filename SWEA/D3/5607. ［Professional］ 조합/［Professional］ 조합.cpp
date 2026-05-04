#include <iostream>

#define devide 1234567891

using namespace std;


/* 페르마의 소정리 */
long long perma(long long base, long long exp) {
    long long res = 1;

    base %= devide;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % devide;
        }

        base = (base * base) % devide;
        exp /= 2;
    }

    return res;
}


int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int n, r;
        cin >> n >> r;

        long long over = 1;
        long long under = 1;

        // 분자: n! 계산
        for (int j = 1; j <= n; j++) {
            over = (over * j) % devide;
        }

        // 분모: r! * (n-r)! 계산
        for (int j = 1; j <= r; j++) {
            under = (under * j) % devide;
        }
        for (int j = 1; j <= n - r; j++) {
            under = (under * j) % devide;
        }

        // 모듈러 역원 계산
        long long inverse = perma(under, devide - 2);

        // 분자 * 분모의 역원
        long long answer = (over * inverse) % devide;

        cout << "#" << i + 1 << " " << answer << "\n";
    }

    return 0;
}