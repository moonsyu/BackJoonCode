#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> answer;

void back_tracking(vector<bool>& visit, int now, int count) {
	if (count >= m) {
		for (int a : answer) {
			cout << a << " ";
		}
		cout << now << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) {
			visit[i] = false;
			answer.push_back(now);
			
			back_tracking(visit, i, count + 1);
			
			visit[i] = true;
			answer.pop_back();
		}
	}
}


int main() {
	cin >> n >> m;

	vector<bool> visit(n + 1, true);
	for (int i = 1; i <= n; i++) {
		visit[i] = false;
		back_tracking(visit, i, 1);
		visit[i] = true;
	}
}