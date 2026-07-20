#include <iostream>

using namespace std;

int main() {
 
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int tc;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
     	long long a, b;
        cin >> a >> b;
        
        long long answer = (a * a) / (b * b);
        cout << "#" << t << " " << answer << endl;
    }
}