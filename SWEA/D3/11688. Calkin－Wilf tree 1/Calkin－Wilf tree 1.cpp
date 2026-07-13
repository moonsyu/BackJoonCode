#include <iostream>
#include <string>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        string s;
        cin >> s;

        int a, b;
        a = b = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                b += a;
            } else {
                a += b;
            }
        }

        cout << "#" << t << " " << a << " " << b << endl;
    }
}