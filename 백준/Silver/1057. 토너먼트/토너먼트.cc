/*
* 문제이해
* 1. 토너먼트에서 1번 ~ N번까지 번호를 배정 받는다
* 2. 1번은 2번과, 3번은 4번과 대진하는 형태로 계산한다
* 3. 2번이 이기고 3번이 이길경우 다음 라운드에서 해당 선수들은 각각 1번과 2번을 배정받는다
* 4. 김지민과 임한수의 번호를 입력받았을때 몇번째 라운드에서 서로 대진하게 되는가
* 
* 문제풀이
* 1. n(참가자수), gim(김지민 번호), im(임한수 번호)를 입력받는다
* 2. deque에 1 ~ n까지의 수를 입력받는다
* 3. 2개씩 꺼내어 김지민과 임한수인지 확인한다
* 4. 아니라면 앞에 먼저 꺼낸 숫자를 다시 뒤로 넣는다
* 5. 김지민이 나온다면 gim_check = 1
* 6. 임한수가 나온다면 im_check = 1
* 7. 둘다 check 가 1이라면 round++, gim(im)_check = 0
* 8. 둘이 같이 나올때 까지 반복한다.
**/

#include<iostream>
#include<deque>

using namespace std;

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, gim, im;

	cin >> n >> gim >> im;

	deque<int> number;

	for (int i = 1; i <= n; i++) {
		number.push_back(i);
	}

	int gim_check = 0;
	int im_check = 0;
	int round = 0;
	bool escape = false;

	while (!escape) {
		int one, two;
		bool push;
		int size = number.size();
		if (size == 1) {
			round = -1;
			break;
		}

		if (size % 2 == 1) {
			for (int i = 0; i < size / 2; i++) {
				push = true;

				one = number.front();
				number.pop_front();
				two = number.front();
				number.pop_front();

				if (one == gim || two == gim) {
					gim_check = 1;
					number.push_back(gim);
					push = false;
				}
				if (one == im || two == im) {
					im_check = 1;
					number.push_back(im);
					push = false;
				}
				if(push) {
					number.push_back(one);
				}

				if (gim_check == 1 && im_check == 1) {
					gim_check = 0;
					im_check = 0;
				}

				if ((one == gim && two == im) || (one == im && two == gim)) {
					escape = true;
					break;
				}
			}
			if (number.front() == gim)
				gim_check = 1;
			else if (number.front() == im)
				im_check = 1;

			number.push_back(number.front());
			number.pop_front();
			round++;
		}
		else {
			for (int i = 0; i < size / 2; i++) {
				push = true;

				one = number.front();
				number.pop_front();
				two = number.front();
				number.pop_front();

				if (one == gim || two == gim) {
					gim_check = 1;
					number.push_back(gim);
					push = false;
				}
				if (one == im || two == im) {
					im_check = 1;
					number.push_back(im);
					push = false;
				}
				if (push) {
					number.push_back(one);
				}

				if (gim_check == 1 && im_check == 1) {
					gim_check = 0;
					im_check = 0;
				}

				if ((one == gim && two == im) || (one == im && two == gim)) {
					escape = true;
					break;
				}
			}
			round++;
		}
	}

	cout << round;

}