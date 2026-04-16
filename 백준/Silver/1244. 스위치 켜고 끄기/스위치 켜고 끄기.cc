#include<iostream>
#include<deque>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int size;
    
    cin >> size;
    
    deque<bool> swit;
    
    for(int i = 0; i < size; i++){
        int num;
        cin >> num;
        if(num == 1)
            swit.push_back(true);
        else
            swit.push_back(false);
    }
    
    cin >> size;
    
    for(int i = 0; i < size; i++){
        int sex, num;
        
        cin >> sex >> num;
        num = num - 1;
        if(sex == 1)
            for(int j = num; j < swit.size(); j += num + 1)
                swit[j] = !swit[j];
        else{
            int index = 1;
            swit[num] = !swit[num];
            while(true){
                if(num - index > -1 && num + index < swit.size())
                    if(swit[num - index] == swit[num + index]){
                        swit[num - index] = !swit[num - index];
                        swit[num + index] = !swit[num + index];     
                        index++;
                    }
                    else
                        break;
                else
                    break;
            }
        }
    }
    
    
    for(int i = 0; i < swit.size(); i++){
            if(swit[i])
                cout << 1;
            else
                cout << 0;
        
            if((i + 1) % 20 != 0 )
                cout << " ";
            else if(swit.size() > i + 1)
                cout << "\n";
     
    }
}