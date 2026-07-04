#include <string>
#include <vector>

using namespace std;

/**

2 3 2      5 4 3           (2 * 5 + 3 * 4 + 2 * 3)
4 2 4      2 4 1     ->    
3 1 4      3 1 1

*/

vector<int> find_arr1(vector<vector<int>> arr1, int row) {
    vector<int> result;
    for (int i = 0; i < arr1[0].size(); i++) {
        result.push_back(arr1[row][i]);
    }
    
    return result;
}


vector<int> find_arr2(vector<vector<int>> arr2, int col) {
    vector<int> result;
    for (int i = 0; i < arr2.size(); i++) {
        result.push_back(arr2[i][col]);
    }
    
    return result;
}



int calc (vector<int> arr1_temp, vector<int> arr2_temp) {
    int result = 0;
    for (int i = 0; i < arr1_temp.size(); i++) {
        result += arr1_temp[i] * arr2_temp[i];
    }
    
    return result;
}


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int> (arr2[0].size()));
    
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            answer[i][j] = calc(find_arr1(arr1, i), find_arr2(arr2, j));
        }
    }
    
    return answer;
}