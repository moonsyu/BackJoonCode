#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /**
     * 숫자를 오름차순으로 정렬 후 중간 값을 출력한다.
     * 입력 받는 수의 개수는 항장 홀수이다.
     * 
     * -- 자연어 풀이 --
     * 1. 숫자들을 입력받아 vector에 저장한다
     * 2. vector를 오름차순으로 정렬한다
     * 3. vector의 중간 인덱스에 들어있는 값을 출력한다.
     */

     long long n;
     cin >> n;

    vector<long long> num;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());

    cout << num[n / 2];

}