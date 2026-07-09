#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<pair<int, int>> kind;
    int sum = brown + yellow;
    for (int y = 3; y <= sum; y++) {
        if(!(sum % y)) {
            if (sum / y >= y) {
                kind.push_back({y, sum / y});
            } else {
                break;
            }
        }
    }
    
    
    for (int i = 0; i < kind.size(); i++) {
        if ((kind[i].first + kind[i].second) * 2 - 4 == brown && kind[i].first * kind[i].second - brown == yellow) {
            answer.push_back(kind[i].second);
            answer.push_back(kind[i].first);
            break;
        }
    }
    
    return answer;
}