#include <iostream>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        long long d, l, n;
        cin >> d >> l >> n;

        long long answer = d * ((n - 1) * n / 2) * l;
        cout << "#" << t << " " << (answer / 100 + n * d) << endl;
    }
}