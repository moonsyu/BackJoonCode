#include<iostream>
#include<set>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int n,m;
    set<long long> a;
    
    cin >> n >> m;
    
    long long del = 0;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a.insert(num);
    }
    
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        if(a.find(num) != a.end())
            del++;
        else
            a.insert(num);
    }
    
    cout << a.size() - del;
}
