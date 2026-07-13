#include <iostream>
#include <string>

using namespace std;

int main() {
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++) {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int answer = 0;
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] == s2[i]) {
        answer++;
      }
    }

    cout << "#" << t << " " << answer << endl;
  }
}