#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/* 메모리 절약 버전 */
int memory_save(vector<int> &elements) {
    int result = 0;
    
    vector<int> calc;
    for (int i = 1; i <= elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            int sum = 0;
            for (int k = j; k < j + i; k++) {
                sum += elements[k % elements.size()];
            }
            
            calc.push_back(sum);
        }
    }
    
    sort(calc.begin(), calc.end());
    
    int num = 0;
    for (int i = 0; i < calc.size(); i++) {
        if (num != calc[i]) {
            result++;
            num = calc[i];
        }
    }
    
    return result;
}


/* 시간 절약 버전 */
int time_save(vector<int> &elements) {
    int result = 0;
    
    vector<bool> calc(1000001, true);
    for (int i = 1; i <= elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            int sum = 0;
            for (int k = j; k < j + i; k++) {
                sum += elements[k % elements.size()];
            }
            
            if (calc[sum]) {
                result++;
                calc[sum] = false;
            }
        }
    }
    
    return result;
}


int solution(vector<int> elements) {
    int answer = 0;
    
    
    // answer = memory_save(elements); // 메모리 절약
    answer = time_save(elements); // 시간 절약
    return answer;
}