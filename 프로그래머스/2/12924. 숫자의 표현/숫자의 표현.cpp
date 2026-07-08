#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <=n; i++) {
        int num = i;
        int sum = 0;
        while (sum < n) {
            sum += num++;
            
            if (sum == n) {
                answer++;
            }
        }
    }
    
    return answer;
}