#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int min_num = arr[0];
    int min_idx = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min_num) {
            min_num = arr[i];
            min_idx = i;
        }
    }
    
    for (int i = 0; i < arr.size(); i++) {
        if (i != min_idx) {
            answer.push_back(arr[i]);
        }
    }
    
    if (!answer.size()) {
        answer.push_back(-1);
    }
    
    return answer;
}