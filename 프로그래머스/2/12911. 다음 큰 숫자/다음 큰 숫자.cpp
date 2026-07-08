#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/* 1의 개수 조회 */
int select_one_cnt(int num) {
    int result = 0;
    
    while(num > 0) {
        if (num % 2) {
            result++;
        } 
        
        num /= 2;
    }
    
    return result;
}


int solution(int n) {
    int answer = 0;
    
    int n_cnt = select_one_cnt(n);
    
    while(select_one_cnt(++n) != n_cnt) {
        continue;
    }
    
    answer = n;
    return answer;
}