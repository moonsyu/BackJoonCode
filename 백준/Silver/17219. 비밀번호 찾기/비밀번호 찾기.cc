#include <iostream>
#include <map>

using namespace std;

int main() {
    /**
     * 비밀번호 찾기
     * https://www.acmicpc.net/problem/17219
     * 
     * 입력 값을 map에 저장하여, 
     * 주어진 key값에 해당하는 value값을 출력하는 문제
     * 
     * -- 자연어 풀이 --
     * 1. n과 m을 입력 받는다
     * 2. n번 반복하여 map에 key와 value를 저장한다
     * 3. m번 반복하며 입력받은 key에 해당하는 value를 출력한다
     * 
     */

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    map<string, string> word;
    for (int i = 0; i < n; i++) {
        string key, value;
        cin >> key >> value;
        word[key] = value;
    }

    for (int i = 0; i < m; i++) {
        string key;
        cin >> key;
        cout << word[key] << "\n";
    }
}