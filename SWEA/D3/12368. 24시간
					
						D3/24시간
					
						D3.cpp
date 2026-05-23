#include <iostream>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
    	int start, end;
        cin >> start >> end;
        
        cout << "#" << t << " " << (start + end) % 24 << "\n";
    }
}