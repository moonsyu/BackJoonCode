#include<iostream>

using namespace std;

int main(){
    char chess;
    int answer = 0;
    
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            cin >> chess;
            if(chess == 'F' && (i + j) % 2 == 0)
                answer++;
            
        }
    cout << answer;
}