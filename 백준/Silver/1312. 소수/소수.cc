#include <iostream>

using namespace std;

int main()
{
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int x, y, n, answer;
    
    cin >> x >> y >> n;
    
    long long count = -1;
    
    while(count != n){
        answer = x / y;
        x = x % y * 10;
        count++;
    }
    
    cout << answer;
}