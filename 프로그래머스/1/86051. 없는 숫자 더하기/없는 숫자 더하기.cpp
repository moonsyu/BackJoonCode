#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> exists(10, true);
    for (int i = 0; i < numbers.size(); i++) {
        exists[numbers[i]] = false;
    }
    
    for (int i = 0; i < exists.size(); i++) {
        if (exists[i]) {
            answer += i;
        }
    }
    
    return answer;
}