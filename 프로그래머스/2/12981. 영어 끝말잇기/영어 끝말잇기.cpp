#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void map_set(vector<string> &words, map<string, bool> &m) {
    for (string s : words) {
        m[s] = false;
    }
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    
    map<string, bool> m;
    map_set(words, m);
    
    char last_alpha = words[0][0];
    for (int i = 0; i < words.size(); i++) {
        // 끝말잇기 확인
        if (last_alpha != words[i][0]) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        } else {
            last_alpha = words[i][words[i].length() - 1];
        }
        
        // 중복 단어 확인
        if(m[words[i]]) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        } else {
            m[words[i]] = true;
        }
    }
    
    return answer;
}