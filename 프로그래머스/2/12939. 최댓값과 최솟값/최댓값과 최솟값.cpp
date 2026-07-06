#include <string>
#include <vector>

using namespace std;


/* 초기 값 할당 */
int set_num(string &s, int &min, int &max) {
    string now_num = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            now_num += s[i];
        } else {
            return stoi(now_num);
        }
    }
}


string solution(string s) {
    string answer = "";
    
    int min_num, max_num;
    min_num = max_num = set_num(s, min_num, max_num);
    
    string now_num = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            now_num += s[i];
        } else {
            min_num = min(min_num, stoi(now_num));
            max_num = max(max_num, stoi(now_num));
            now_num = "";
        }
    }
    
    min_num = min(min_num, stoi(now_num));
    max_num = max(max_num, stoi(now_num));
    
    answer = to_string(min_num) + " " + to_string(max_num); 
    return answer;
}