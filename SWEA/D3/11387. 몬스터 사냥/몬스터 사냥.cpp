#include <iostream>

using namespace std;

int main() {

  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++) {
    int d, l, n;
    cin >> d >> l >> n;

    long long answer = 0;
    for (int i = 0; i < n; i++) {
      answer += d * i * l;
    }

    answer /= 100;
    answer += n * d;

    cout << "#" << t << " " << answer << endl;
  }
}