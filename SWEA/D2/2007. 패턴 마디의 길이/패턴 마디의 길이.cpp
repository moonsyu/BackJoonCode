#include <iostream>
#include <string>

using namespace std;

int main() {

	/**
	* 특정 단어로 이루어진 문자열에서 반복되는 단어의 길이를 구하라
	* 
	* -- 자연어 풀이 --
	* 1. s를 입력 받는다
	* 2. 반복문으로 s를 돈다
	* 3. 한 문자 씩 word에 넣는다
	* 4. i까지 word에 넣었다면 i + 1 ~ i + word.size() - 1 까지 word와 같은지 비교한다
	* 5. 같다면 단어의 시작 위치와 끝 위치를 word.size()만큼 옮겨가며 옳은 단어인지 확인한다
	* 
	*/

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		string s;
		cin >> s;

		string word = "";
		for (int j = 0; j < s.size(); j++) {
			word += s[j];

			if (s.substr(j + 1, word.size()) == word) {
				bool pass = true;

				for (int k = j + 1; k < s.size() - word.size(); k += word.size()) {
					if (s.substr(k, word.size()) != word) {
						pass = false;
						break;
					}
				}

				if (pass) {
					break;
				}
			}
		}

		cout << "#" << i + 1 << " " << word.size() << "\n";
	}
}