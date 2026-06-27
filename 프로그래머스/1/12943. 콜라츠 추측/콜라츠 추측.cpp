#include <string>
#include <vector>

using namespace std;

int solution(int input_num) {
    long long num = input_num;  
    int answer = 0;
    
    int cnt = 0;
    while (++cnt <= 500 && num != 1) {
        if (num % 2) {
            num = num * 3 + 1;
        } else {
            num /= 2;
        }
    }
    
    if (cnt >= 500) {
        answer = -1;
    } else {
        answer = cnt - 1;
    }
    
    return answer;
}