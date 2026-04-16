#include <iostream>
#include<cstring>
#include<algorithm>
#include<deque>

using namespace std;

int main()
{
    string name;
    
    cin >> name;
    
    deque<char> answer;
    
    for(int i = 0; i < name.size(); i++){
        answer.push_back(name[i]);
    }
    
    sort(answer.begin(), answer.end());
    
    deque<char> solo;
    deque<char> stack;
    int count = 1;
    char current = answer[0];
    answer.push_back('\n');
    
    for(int i = 1; i < answer.size(); i++){
        if(current != answer[i]){
            if(count % 2 != 0)
                solo.push_back(current);
            
            for(int j = 0; j < count / 2; j++)
                    stack.push_back(current);
                
                current = answer[i];
                count = 1;
        }
        else{
            count++;
        }
    }
    
    if(solo.size() > 1)
        cout << "I'm Sorry Hansoo";
    else{
        for(int i = 0; i < stack.size(); i++)
            cout << stack[i];
            
        if(!solo.empty())
            cout << solo[0];
            
        for(int i = stack.size() - 1; i >= 0; i--)
            cout << stack[i];
    }
}
