#include <string>
#include <vector>
#include <cmath>

using namespace std;

int num_cnt[50001];

long long solution(int n, vector<int> works) {    
    int max_num = 0;
    int work_size = works.size();
    for (int i = 0; i < work_size; i++) {
        num_cnt[works[i]]++;
        max_num = max(max_num, works[i]);
    }
    
    while(n) {        
        if (num_cnt[max_num]) {
            n--;
            num_cnt[max_num]--;
            num_cnt[max_num - 1]++;
        } else {
            max_num--;
        }
    }
    
    long long answer = 0;
    for (int i = 0; i < 50000; i++) {
        answer += i * i * num_cnt[i];
    }
    
    return answer;
}