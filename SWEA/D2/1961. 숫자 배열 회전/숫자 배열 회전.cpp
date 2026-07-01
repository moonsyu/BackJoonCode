#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        cout << "#" << tc << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[n - 1 - j][i];
            }
            cout << " ";

            for (int j = 0; j < n; j++) {
                cout << arr[n - 1 - i][n - 1 - j];
            }
            cout << " ";

            for (int j = 0; j < n; j++) {
                cout << arr[j][n - 1 - i];
            }
            cout << "\n";
        }
    }
}