#include <iostream>
#include <string>

using namespace std;

int main() {
    
 	int tc;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
        int n;
        cin >> n;
        
        string input;
        cin >> input;

        string answer = "No";
        string s = "";
        s += input.front();
        for (int i = 1; i < input.size(); ) {
         	if (input.substr(i, i + s.size()) == s) {
             	answer = "Yes";
                i += s.size();
            } else {
             	answer = "No";
                s += input[i];
                i++;
            }
        }
     	
        cout << "#" << t << " " << answer << endl;
    }
}