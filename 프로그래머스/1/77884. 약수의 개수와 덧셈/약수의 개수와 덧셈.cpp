#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    long long answer = 0;
    
    for (int i = left; i <= right; i++) {
        
        // 약수 개수 확인
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                cnt++;
            }
        }
        
        
        if (cnt % 2) { // 약수의 개수가 홀수 일 경우
            answer -= i;
        } else { // 약수의 개수가 짝수 일 경우
            answer += i;
        }
    }
    
    return answer;
}