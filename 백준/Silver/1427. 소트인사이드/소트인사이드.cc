#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    string s;

    cin >> s;

    sort(s.begin(), s.end());

    for(int i = s.size() - 1; i >= 0; i--)
        cout << s[i];
}