#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int tc;
    cin >> tc;
    
    vector<bool> lost(26, true);
    lost[0] = lost[4] = lost[8] = lost[14] = lost[20] = false;

    for (int t = 1; t <= tc; t++) {
    	string input;
        cin >> input;
        
        cout << "#" << t << " ";
        for (char c : input) {
        	if (lost[c - 97]) {
            	cout << c;
            }
        }
        cout << "\n";
        
    }
}