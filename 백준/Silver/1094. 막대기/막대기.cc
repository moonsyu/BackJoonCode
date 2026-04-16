#include<iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    int x = 64, count = 0;
    while(true){
        if(x > n){
            x /= 2;
        }
        else if(x < n){
            count++;
            n -= x;
        }
        else{
            count++;
            break;
        }
    }

    cout << count;
}