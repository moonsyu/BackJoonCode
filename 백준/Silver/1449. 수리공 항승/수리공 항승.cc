#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int n, l;
    
    deque<int> pipe(1001, 0);
    
    cin >> n >> l;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        pipe[num] = 1;
    }
    
    int count = 0;
    for(int i = 1; i < 1001; i++){
        if(pipe[i] == 1){
            bool check = true;
            for(int j = 0; j < l; j++){
                if(pipe[i + j] == 1){
                    pipe[i + j] = 2;
                }
                else if(pipe[i + j] == 2){
                    check = false;
                    break;
                }
                
                if(i + j + 1 > 1000)
                    break;
            }
            if(check)
                count++;
        }
    }
    
    cout << count;
}
