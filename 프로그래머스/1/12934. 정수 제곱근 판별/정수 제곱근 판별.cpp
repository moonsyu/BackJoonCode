#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

	long double sqrt_n = sqrt(n);
    if (sqrt_n == (long long)sqrt_n) {
        answer = (long long)pow(sqrt_n + 1, 2);
    } else {
        answer = -1;
    }

    return answer;
}