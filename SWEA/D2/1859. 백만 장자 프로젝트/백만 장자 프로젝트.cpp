#include <iostream>
#include <vector>

using namespace std;

int main() {
    /**
     * 각 날마다 물건의 가격이 주어졌을 때
     * 해당 물건을 사거나 팔며 최대 이익을 구하라
     * 물건은 각 날마다 최대 1개씩만 살 수 있으며, 언제든 팔 수 있다.
     * 물건을 안 살 수도 있다.
     * 
     * -- 자연어 풀이 --
     * 1. n일을 입력 받는다.
     * 2. n일 동안의 물건 가격을 입력 받아 vector에 저장한다.
     * 3. vector를 순회한다
     * 4. 현재 회차의 가격이 다음 회차보다 낮을 경우 물건을 산다
     * 5. 현재 까지 구매한 물건 가격이 다음 회차보다 낮을 경우 물건을 판다
     * 6. 물건을 팔 경우 최대 이익에 판매 가격을 더한 후 구매한 물건 가격을 초기화 한다
     * 7. 최대 이익을 출력한다.
     * 
     * -- 추가 수정 사항 --
     * 1. 구매가와 판매가를 비교해야 한다.
     * 2. 마지막 회차부터 찾아본다
     *    ㄴ 마지막 회차의 가격을 최대 가로 가정한다
     *    ㄴ 현재가가 최대가 보다 작다면 answer += 최대가 - 현재가
     */

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        long long n;
        cin >> n;

        long long answer = 0;
        vector<long long> price(n);
        for (int j = 0; j < n; j++) {
            cin >> price[j];
        }

        long long max_price = price[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            if (price[j] < max_price) {
                answer += max_price - price[j];
            } else {
                max_price = price[j];
            }
        }

        cout << "#" << i + 1 << " " << answer << "\n";
    }
}