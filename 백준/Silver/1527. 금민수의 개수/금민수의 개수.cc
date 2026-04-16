#include<iostream>
#include<algorithm>
#include<string>
#include<deque>

using namespace std;

void four_seven(deque<string> &save, string msg, string num, int start, int end) {
	msg += num;
	//cout << msg << " ";
	if (msg.size() <= end && msg.size() <= 9) {
		//cout << "push\n";
		if(msg.size() >= start)
			save.push_back(msg);
		four_seven(save, msg, "4", start, end);
		four_seven(save, msg, "7", start, end);
	}
	
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string A, B;
	deque<string> save;

	cin >> A >> B;

	four_seven(save, "", "4", A.size(), B.size());
	four_seven(save, "", "7", A.size(), B.size());
	
	long long count = 0;
	
	long long first = stol(A), second = stol(B);

	for (int i = 0; i < save.size(); i++) {
		//cout << save[i] << " ";
		if (stol(save[i]) >= first && stol(save[i]) <= second)
			count++;
	}

	cout << count;

}