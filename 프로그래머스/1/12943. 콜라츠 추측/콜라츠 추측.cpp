#include <string>
#include <vector>

using namespace std;

int solution(int input_num) {
    long long num = input_num;  
    int answer = 0;
    
    int cnt = 0;
    while (++cnt <= 500 && num != 1) {
        num = num % 2 ? num * 3 + 1 : num / 2;
    }
    
    answer = cnt >= 500 ? -1 : cnt - 1;
    return answer;
}