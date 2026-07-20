#include <iostream>
#include <iomanip>

using namespace std;

int main() {
 	
    int tc;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
     	double d, a, b, f;
        cin >> d >> a >> b >> f;
        
        cout << "#" << t << " " << fixed << setprecision(10) << d / (a + b) * f << endl;
    }
}