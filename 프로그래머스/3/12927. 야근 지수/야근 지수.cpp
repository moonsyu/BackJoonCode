#include <string>
#include <vector>
#include <iostream>
using namespace std;

int num_cnt[50001];

long long solution(int n, vector<int> works) {    
    int max_num = 0;
    int work_size = works.size();
    for (int i = 0; i < work_size; i++) {
        num_cnt[works[i]]++;
        max_num = max(max_num, works[i]);
    }
    
    long long answer = 0;
    for (int i = max_num; i >= 0; i--) {
        if (num_cnt[i] && n) {
            n--;
            num_cnt[i - 1]++;
            num_cnt[i++]--;
        }
        
        if (!n) {
            answer += i * i * num_cnt[i];
        }
    }
    
    return answer;
}