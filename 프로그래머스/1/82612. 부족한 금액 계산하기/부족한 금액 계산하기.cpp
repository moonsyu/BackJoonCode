using namespace std;

long long solution(int price, int money, int count){
    long long answer = -1;
    
    long long total_price = 0;
    for (int i = 1; i <= count; i++) {
        total_price += price * i;
    }
    
    answer = total_price - money <= 0 ? 0 : total_price - money;
    return answer;
}