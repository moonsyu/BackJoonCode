#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    /**
     * X : max(A, B) -> A와 B의 최대값
     * Y : max(B, C) -> B와 C의 최대값
     * Z : max(C, A) -> C와 A의 최대값
     * 
     * X, Y, Z가 주어질 때 A, B, C값을 찾아라
     * 
     * -- 자연어 풀이 (Brute Force)--
     * 1. x, y, z를 입력 받는다
     * 2. x, y, z에 따라 a, b, c의 값 범위를 구한다
     * 3. 각 범위의 숫자를 모두 돌려보며 가능한 값이 있는지 찾는다
     * 
     * -- 추가 수정 사항 --
     * 1. 범위가 아닌 값을 할당한다 (x 값을 a or b에 할당한 후 y, z에 따라 b, c에 할당)
     * 2. x, y, z가 모두 같다면 a, b, c의 값은 x, y, z와 동일하다
     * */

    long long tc;
    cin >> tc;

    for (long long i = 0; i < tc; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        long long a, b, c;
        if (x == y && y == z) {
            cout << x << " " << y << " " << z << "\n";
        } else if (x == y) {
            b = x;
            if (z > x) {
                cout << "-1 -1 -1\n";
            } else {
                c = z;
                a = z;
                cout << a << " " << b << " " << c << "\n";
            }
        } else if (x == z) {
            a = x;
            if (y > x) {
                cout << "-1 -1 -1\n";
            } else {
                c = y;
                b = y;
                cout << a << " " << b << " " << c << "\n";
            }
        } else if (y == z) {
            c = y;
            if (x > y) {
                cout << "-1 -1 -1\n";
            } else {
                a = x;
                b = x;
                cout << a << " " << b << " " << c << "\n";
            }
        } else {
            cout << "-1 -1 -1\n";
        }
    }


}