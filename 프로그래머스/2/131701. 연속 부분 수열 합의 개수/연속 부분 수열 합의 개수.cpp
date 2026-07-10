#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    
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
            answer++;
            num = calc[i];
        }
    }
    
    return answer;
}