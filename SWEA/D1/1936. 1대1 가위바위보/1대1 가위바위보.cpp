#include <iostream>

using namespace std;

int main() {

    /**
     * 가위바위보
     * A와 B의 입력을 받아서 누가 이겼는지 출력
     * 1: 가위, 2: 바위, 3: 보
     * 
     * -- 자연어 풀이 --
     * 1. a, b를 입력 받는다
     * 2. a와 b가 각각 1, 3 이거나 3, 1일 경우 1인 쪽이 이긴다.
     * 3. 그 외 숫자가 더 큰 쪽이 이긴다
     */

    long long a, b;
    cin >> a >> b;
    
    if ((a == 1 && b == 3) || (a == 3 && b == 1)) {
        if (a > b) {
            cout << "B\n";
        } else {
            cout << "A\n";
        }
    } else {
        if (a > b) {
            cout << "A\n";
        } else {
            cout << "B\n";
        }
    }
}