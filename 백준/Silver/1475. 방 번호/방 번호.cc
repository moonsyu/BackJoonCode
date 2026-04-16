#include <iostream>
#include<deque>

using namespace std;

int main()
{
    string room;
    deque<long long> num(9, 0);
    
    cin >> room;
    
    for(int i = 0; i < room.size(); i++){
        if(room[i] == '9')
            num[6]++;
        else
            num[room[i] - '0']++;
    }
    
    if(num[6] > 1){
        if(num[6] % 2 != 0)
            num[6]++;
        num[6] /= 2;
    }
    
    int index, max = 0;
    for(int i = 0; i < num.size(); i++){
        if(num[i] > max){
            max = num[i];
            index = i;
        }
    }
    
    cout << max;
}
