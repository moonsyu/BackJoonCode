#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, -1);
    
    int start_idx;
    start_idx = 0;
    
    int sum = 0;
    for (int i = start_idx; i < sequence.size(); i++) {
        sum += sequence[i];
        
        if (sum == k) {
            if (answer[0] == -1 || answer[1] - answer[0] > i - start_idx) {
                answer[0] = start_idx;
                answer[1] = i;
            } 
        } else if (sum > k) {
            sum -= sequence[i--];
            sum -= sequence[start_idx++];
        }
    }
    
    return answer;
}