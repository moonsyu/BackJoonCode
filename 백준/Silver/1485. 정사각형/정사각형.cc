/*
* 문제이해
* 네개의 점이 주어졌을때 해당 점들로 정사각형을 만들수 있는지 확인하라
* 
* 문제풀이
* 1. 점 4개의 좌표를 입력받는다
* 2. 0번째 좌표에서 1 ~ 3번째 좌표와의 거리를 비교한다
* 3. 가장 짧은 좌표의 인덱스를 배열에 저장해둔다
* 4. 해당 좌표까지의 거리를 lang과 비교한다
* 5. 저장된 좌표를 제외한 나머지 좌표와의 거리를 비교한다
* 6. 가장 짧은 좌표의 인덱스를 배열에 저장해둔다
* 7. 해당 좌표까지의 거리를 lang과 비교한다
* 8. 만약 다르다면 정사각형이 아니다
**/

#include<iostream>
#include<cmath>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		deque<int> x(4);
		deque<int> y(4);
		deque<double> lang;

		for (int j = 0; j < 4; j++)
			cin >> x[j] >> y[j];

		for (int i = 0; i < 4; i++)
			for (int j = i + 1; j < 4; j++)
					lang.push_back(sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)));
		
		sort(lang.begin(), lang.end());

		if (lang[4] == lang[5])
			if (lang[0] == lang[1] && lang[1] == lang[2] && lang[2] == lang[3])
				cout << 1;
			else
				cout << 0;
		else
			cout << 0;
		cout << "\n";
	}

}