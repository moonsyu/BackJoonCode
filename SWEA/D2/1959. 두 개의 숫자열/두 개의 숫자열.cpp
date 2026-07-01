#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long compare(vector<long long>& l_vec, vector<long long>& s_vec) {
    long long answer = 0;
    for (int i = 0; i <= l_vec.size() - s_vec.size(); i++) {
        long long sum = 0;
        for (int j = 0; j < s_vec.size(); j++) {
            sum += l_vec[i + j] * s_vec[j];
        }
        
        answer = max(answer, sum);
    }

    return answer;
}

int main() {
    /**
     * 2개의 수열을 입력받아 서로 마주보는 숫자들을 곱한 뒤 모두 더한 값의 최댓값을 구하라
     * 
     * -- 자연어 풀이 --
     * 1. n과 m 입력
     * 2. n과 m의 크기 만큼 수 입력받아 각 a, b 벡터에 저장
     * 3. a, b 벡터의 크기를 비교하여 긴 벡터를 l_vec, 짧은 벡터를 s_vec로 compare 함수에 전달
     * 4. compare 함수에서는 반복문을 통해 i ~ 긴 벡터의 길이 - 짧은 벡터의 길이 까지 반복
     * 5. 내부 반복문에서는 j ~ 짧은 벡터의 길이 까지 반복하며 
     * 6. sum에 긴 벡터의 i + j 번째 요소와 짧은 벡터의 j 번째 요소를 곱한 값을 더한다.
     * 7. sum이 answer보다 클 경우 answer에 sum을 저장한다.
     * 8. compare 함수에서 answer를 반환한다.
     * 9. compare 함수에서 반환된 answer를 출력한다.
     */


    long long tc;
    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        long long n, m;
        cin >> n >> m;

        vector<long long> a(n);
        vector<long long> b(m);

        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }

        cout << "#" << i + 1 << " ";
        cout << (n > m ? compare(a, b) : compare(b, a)) << "\n";
    }
}