#include<iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    double sum = 0, max = 0;
    int repeat;
    
    cin >> repeat;
    
    double num[repeat];
    
    for(int i = 0; i < repeat; i++){
        cin >> num[i];
        if(num[i] > max)
            max = num[i];
    }
    
    for(int i = 0; i < repeat; i++){
        num[i] = num[i] / max * 100;
        sum += num[i];
    }
    cout << sum / repeat;
}