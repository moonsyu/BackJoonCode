#include <iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    deque<char> name;
    
    for(int i = 0; i < n; i++){
        string nm;
        cin >> nm;
        name.push_back(nm[0]);
    }
    
    sort(name.begin(), name.end());
    
    int count;
    char sn;
    
    deque<char> sung;
    for(int i = 0; i < n; i++){
        if(sn == name[i])
            count++;
        else{
            count = 1;
            sn = name[i];
        }
        
        if(count == 5)
            sung.push_back(sn);
    }
    
    if(sung.empty())
        cout << "PREDAJA";
    else
        for(int i = 0; i < sung.size(); i++)
            cout << sung[i];
}
