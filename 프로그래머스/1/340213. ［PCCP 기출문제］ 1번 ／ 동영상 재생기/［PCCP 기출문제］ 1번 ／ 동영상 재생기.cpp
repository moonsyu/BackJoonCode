#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 특정 문자에 따른 split
vector<string> split(string text, char c){
    
    vector<string> arr;
    int split_index = text.find(c);
    arr.push_back(text.substr(0, split_index));
    arr.push_back(text.substr(split_index + 1, text.length()));
    
    return arr;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // 계산이 쉬운 int형으로 변환
    vector<string> arr = split(video_len, ':');
    int total_len = stoi(arr[0]) * 60 + stoi(arr[1]);
    
    arr = split(pos, ':');
    int time = stoi(arr[0]) * 60 + stoi(arr[1]);
    
    arr = split(op_start, ':');
    int op_time = stoi(arr[0]) * 60 + stoi(arr[1]);
    
    arr = split(op_end, ':');
    int op_end_time = stoi(arr[0]) * 60 + stoi(arr[1]);
    
    // command에 따른 시간 계산
    for (string command : commands) {
        if (time >= op_time && time <= op_end_time) {
            time = op_end_time;
        }
        
        if (command == "prev"){
            time -= 10;
            
            if (time < 0) {
                time = 0;
            }
        } else if (command == "next") {
            time += 10;
            
            if (time > total_len) {
                time = total_len;
            }
        }
    }
    
    // 마지막 command 입력 후 오프닝 시간 확인
    if (time >= op_time && time <= op_end_time) {
        time = op_end_time;
    }
    
    // int -> string
    string tt;
    if (time / 60 < 10) {
        tt += "0" + to_string(time / 60);
    } else {
        tt = to_string(time / 60);
    }
    
    string mm;
    if (time % 60 < 10) {
        mm += "0" + to_string(time % 60);
    } else {
        mm = to_string(time % 60);
    }
    
    return tt + ":" + mm;
}