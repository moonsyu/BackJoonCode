#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    int count = 1;
    vector<int> save = {2};
    for(int i = 2; i <= n; i++){
        bool check = true;
        for(int j = save.size() - 1; j >= 0; j--){
            if(i % save[j] == 0){
                if(save[j] <= k)
                    count++;
                check = false;
                break;
            }
        }
        
        if(check){
            if(i <= k)
                count++;
            save.push_back(i);
        }
    }

    cout << count;
}