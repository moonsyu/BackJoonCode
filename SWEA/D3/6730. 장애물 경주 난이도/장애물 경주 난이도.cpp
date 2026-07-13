#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int up = 0;
    int down = 0;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] < arr[i + 1]) {
        up = max(up, arr[i + 1] - arr[i]);
      } else {
        down = max(down, arr[i] - arr[i + 1]);
      }
    } 

    cout << "#" << t << " " << up << " " << down << endl;
  }
}