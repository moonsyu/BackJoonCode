#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


/* 2진수 -> 10진수 변환 */
long long two_to_ten(string origin) {
	
	long long result = 0;
	for (int i = 0; i < origin.size(); i++) {
		result += (origin[i] - '0') * (1 << (origin.size() - 1 - i));
	}

	return result;
}


/* 3진수 -> 10진수 변환 */
long long three_to_ten(string origin) {
	long long result = 0;
	for (int i = 0; i < origin.size(); i++) {
		result += (origin[i] - '0') * pow(3, origin.size() - 1 - i);
	}

	return result;
}


/* 정답 반환 */
long long answer(string two, string three) {

	vector<long long> num_list;

	// 2진수의 각 자리수를 바꾼 수를 num_list에 추가
	long long two_num = two_to_ten(two);
	for (int i = 0; i < two.size(); i++) {
		if (two[i] == '0') {
			long long new_num = two_num + (1 << (two.size() - 1 - i));
			num_list.push_back(new_num);
		}
		else {
			long long new_num = two_num - (1 << (two.size() - 1 - i));
			num_list.push_back(new_num);
		}
	}

	// 3진수의 각 자리수를 바꾼 수가 num_list에 있는지 확인
	long long three_num = three_to_ten(three);
	for (int i = 0; i < three.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (j != (three[i] - '0')) {
				long long new_num = three_num + (j - (three[i] - '0')) * pow(3, three.size() - 1 - i);
				for (long long num : num_list) {
					if (num == new_num) {
						return num;
					}
				}
			}
		}
	}

	return -1;
}



int main() {

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		string two, three;
		cin >> two >> three;

		cout << "#" << t << " " << answer(two, three) << endl;
	}

}