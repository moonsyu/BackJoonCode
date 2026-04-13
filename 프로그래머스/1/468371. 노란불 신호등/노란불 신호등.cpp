#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 최대 공약수
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소 공배수
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

// 배열 값들의 최소 공배수 반환
long long get_lcm(vector<vector<int>> signals) {
    
    vector<int> arr;
    for (long long i = 0; i < signals.size(); i++) {
        long long sum = 0;
        for (int j = 0; j < signals[i].size(); j++){
            sum += signals[i][j];
        }
        arr.push_back(sum);
    }
    
    long long result = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        result = lcm(result, arr[i]);
    }
    
    return result;
}

// main
int solution(vector<vector<int>> signals) {
    int answer = 0;
    
    vector<pair<int, int>> temp(signals.size(), {0, 1});
    
    long long arrays_lcm = get_lcm(signals);
    for (answer = 2; answer < arrays_lcm; answer++){
        int count = 0;
        for (int i = 0; i < signals.size(); i++){
            int color = temp[i].first % signals[0].size();
            int repeat = temp[i].second;
            
            // 불이 바뀌는지 확인
            if (repeat == signals[i][color]) {
                temp[i].first++;
                temp[i].second = 1;
            } else {
                temp[i].second++;
            }
            
            // 현재 노란불인지 확인
            if (temp[i].first % signals[0].size() == 1) {
                count++;
            } else {
                count--;
            }
        }
        
        if (count == signals.size()) {
            return answer;
        }
    }
    
    return -1;
}



