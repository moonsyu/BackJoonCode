#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int answer;

void combination (vector<int> &height, int &b, int idx, int sum) {
    if (sum >= b) {
    	answer = min (answer, sum - b);
    } else {
        for (int i = idx; i < height.size(); i++) {
            combination(height, b, i + 1, sum + height[i]);
        }
    }
}

int main() {
	
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    
    int t;
    cin >> t;
    
    for (int tc = 1; tc <= t; tc++) {
    	int people_cnt, b;
        cin >> people_cnt >> b;
        
        vector<int> height(people_cnt);
        for (int i = 0; i < people_cnt; i++) {
        	cin >> height[i];
        }
        
		answer = 999999;
        combination(height, b, 0, 0);
        
        cout << "#" << tc << " " << answer << endl;
    }
}