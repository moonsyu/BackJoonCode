#include <iostream>
#include <string>
#include <vector>

using namespace std;


/* 사전 초기화 */
void reset_arr(vector<string> &dict) {
    
    char c = 'A';
    for (int i = 0; i < 26; i++) {
        dict[i] = c + i;
    }
}


/* 사전 번호 조회 */
int find_dict_num(vector<string> &dict, string s) {
    for (int i = 0; i < dict.size(); i++) {
        if (dict[i] == s) {
            return i + 1;
        }
    }
}


vector<int> solution(string msg) {
    vector<int> answer;
    
    vector<string> dict(26);
    reset_arr(dict);
    
    for (int i = 0; i < msg.size(); ) { 
        string now_s = "";
        for (int j = i; j < msg.size(); j++) {
            
            // 사전에 있는 단어인지 조회
            int exist = false;
            for (int k = 0; k < dict.size() && !exist; k++) {
                if (dict[k] == (now_s + msg[j])) {
                    exist = true;
                }
            }
            
            if (exist) { // 사전에 있을 경우
                now_s += msg[j];
                if (j + 1 == msg.size()) {      
                    answer.push_back(find_dict_num(dict, now_s));
                }
            } else { // 사전에 없을 경우     
                answer.push_back(find_dict_num(dict, now_s));
                dict.push_back(now_s + msg[j]);
                break;
            }
        }
        
        i += now_s.size();
    }
    
    return answer;
}