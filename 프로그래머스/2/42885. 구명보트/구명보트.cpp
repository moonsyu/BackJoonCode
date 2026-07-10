#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int s_idx = 0;
    int e_idx = people.size() - 1;
    while(s_idx <= e_idx) {
        answer++;
        
        // 무거운 사람 먼저 할당
        int sum = people[e_idx--];
        
        // 이후 가벼운 사람 할당
        if (sum + people[s_idx] <= limit) {
            sum += people[s_idx++];
        }
    }
    
    return answer;
}