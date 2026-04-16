#include <iostream>

using namespace std;

int main() {
    /**
     * 단어를 입력받아 팰린드롬*인지 확인해라
     * 
     * 팰린드롬: 거꾸로 읽어도 동일한 단어
     * 팰린드롬 수: 거꾸로 읽어도 동알한 수
     * 
     * -- 자연어 풀이 --
     * 1. 단어를 입력받는다
     * 2. 단어의 길이를 구한다
     * 3. i와 단어길이 - i가 동일한지 확인한다
     * 4. 다른 알파벳(혹은 글자)라면 answer를 false로 바꾸고 반복문을 종료한다.
     * 5. answer가 true라면 1을 false라면 0을 출력한다
     */

    long long tc;
    cin >> tc;

    for (int i = 0; i < tc; i++){
        string word;
        cin >> word;

        long long word_len = word.length();
        bool answer = true;
        for (int j = 0; j < word_len / 2; j++) {
            if (word[j] != word[word_len - 1 - j]) {
                answer = false;
                break;
            }
        }
        cout << "#" << i + 1 << " " << (answer ? 1 : 0) << "\n";
    }
}