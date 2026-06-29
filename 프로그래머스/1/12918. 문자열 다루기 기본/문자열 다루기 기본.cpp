#include <string>
#include <vector>

using namespace std;

/* 문자열 길이 확인 */
bool leng_check(string s) {
    
    if (s.size() == 4 || s.size() == 6) {
        return true;
    } else {
        return false;
    }
}


/* 숫자 여부 확인 */
bool num_check(string s) {
    bool result = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' > 9) {
            result = false;
            break;
        }
    }
    
    return result;
}


bool solution(string s) {
    bool answer = true;
    
    answer = leng_check(s) && num_check(s);
    return answer;
}