#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 최대 공약수 */
int get_gcm(int a, int b) {
    int num1 = max(a, b);
    int num2 = min(a, b);
    
    if (num1 % num2) {
        return get_gcm(num2, num1 % num2);
    } 
    
    return num2;
}


int solution(vector<int> arr) {
    int answer = 0;
    
    int num = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (num == arr[i]) {
            continue;
        }
        
        num = num * arr[i] / get_gcm(num, arr[i]);
    }
    
    answer = num;
    return answer;
}