#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<int> p_y_cnt(2);
    
    for (char c : s) {
        if (c == 'p' || c == 'P') {
            p_y_cnt[0]++;
        } else if (c == 'y' || c == 'Y') {
            p_y_cnt[1]++;
        }
    }

    answer = p_y_cnt[0] == p_y_cnt[1] ? true : false;
    return answer;
}