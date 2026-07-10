#include <string>
#include <vector>

#define MOD 1234567

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    if (n == 1) {
        answer = 1;
    } else if (n == 2) {
        answer = 2;
    }
    
    int a = 1;
    int b = 2;
    for (int i = 3; i <= n; i++) {
        answer = (a + b) % MOD; // n일 때 값
        
        // 값 업데이트
        a = b;
        b = answer;
    }
    
    return answer;
}