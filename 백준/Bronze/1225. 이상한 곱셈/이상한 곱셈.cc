#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    long long sum = 0;
    string a, b;
    
    cin >> a >> b;
    
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            sum += int(a[i] - '0') * int(b[j] - '0');
    
    cout << sum;
    
}