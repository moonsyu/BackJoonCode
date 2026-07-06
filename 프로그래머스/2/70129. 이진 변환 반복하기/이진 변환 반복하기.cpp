#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
int total_zero_cnt;

/* 0 개수 반환 */
long long response_zero_cnt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            result++;
        }
    }
    
    return result;
}


/* 자연수 -> 2진수 변환 */
string int_to_binary(int num) {
    if (num == 0) return "0";
    
    string result = "";
    while (num > 0) {
        if (num % 2 == 1) result += "1";
        else result += "0";
        num /= 2;
    }
    reverse(result.begin(), result.end());
    
    return result;
}


vector<int> solution(string s) {
    vector<int> answer;
    
    cnt = total_zero_cnt = 0;
    while (s != "1") {
        cnt++;
        
        int zero_cnt = response_zero_cnt(s);
        total_zero_cnt += zero_cnt;
        s = int_to_binary(s.size() - zero_cnt);         
    }
    
    answer.push_back(cnt);
    answer.push_back(total_zero_cnt);
    return answer;
}