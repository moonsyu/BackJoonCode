#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct compare {
	bool operator()(char a, char b) {
		return a > b;
	}
};


long long solution(long long n) {
    long long answer = 0;

	string num = to_string(n);
    sort(num.begin(), num.end(), compare());

    answer = stoll(num);
    return answer;
}