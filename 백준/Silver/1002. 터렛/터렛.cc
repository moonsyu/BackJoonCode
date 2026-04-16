/*
* 문제 이해
* 좌표 2개와 구하고자 하는 좌표까지의 거리가 구해진다
* 해당 정보를 가지고 구하고자 하는 좌표의 개수가 몇개인지 출력하라
* 
* 문제풀이
* 1. 좌표간 거리를 구하는 공식을 이용하여 이차방정식을 세운다
* 2. 두 이차방정식을 하나의 이차방정식으로 합친다
* 3. 각각의 값을 변수 a, b, c에 저장한다
*    a = -2x1 + 2x2,  b = -2y1 + 2y2, c = x1 ^ 2 - x2 ^ 2 + y1 ^ 2 - y2 ^ 2 - r1 ^ 2 + r2 ^ 2
* 4. 판별식을 사용한다
*    (양수라면 2, 0이라면 1, 음수라면 0을 출력한다)
* 5. 4.를 진행하기 전에 입력된 2개의 좌표와 거리가 같다면 -1출력
* 
**/

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int x1, x2, y1, y2, r1, r2;
	double d = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		//if (x1 == x2 && y1 == y2 && r1 == r2)
		//	answer.push_back(-1);
		//else {
		//	int a, b, c;

		//	a = (-2 * x1) + (2 * x2);
		//	b = (-2 * y1) + (2 * y2);
		//	c = pow(x1, 2) - pow(x2, 2) + pow(y1, 2) - pow(y2, 2) - pow(r1, 2) + pow(r2, 2);

		//	if (a != 0) {
		//		d = pow(b, 2) - (4 * a * c);
		//		if (d > 0)
		//			answer.push_back(2);
		//		else if (d == 0)
		//			answer.push_back(1);
		//		else
		//			answer.push_back(0);
		//	}
		//	else {
		//		if (b != 0) {
		//			double y = -c / b;

		//			if (pow(r1, 2) - pow(y - y1, 2) < 0)
		//				answer.push_back(0);
		//			else if (pow(r1, 2) - pow(y - y1, 2) == 0)
		//				answer.push_back(1);
		//			else
		//				answer.push_back(2);
		//		}
		//		else if (c == 0)
		//			answer.push_back(1);
		//		else
		//			answer.push_back(0);
		//	}
		//	//cout << "test : " << a << " " << b << " " << c << " " << d << " \n";
		//}

		double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		if (d == 0 && r1 == r2)
			cout << -1;
		else if (r1 + r2 < d || d + r2 < r1 || d + r1 < r2)
			cout << 0;
		else if (r1 + r2 == d || r1 == r2 + d || r2 == r1 + d)
			cout << 1;
		else if (r1 + r2 > d)
			cout << 2;

		cout << "\n";
	}
}