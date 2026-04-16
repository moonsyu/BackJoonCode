#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int N;

	cin >> N;

	deque<string> student;

	for (int i = 0; i < N; i++) {
		string num;
		cin >> num;
		student.push_back(num);
	}

	sort(student.begin(), student.end());

	int index = 1, erase = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			index = 1;
			for (int k = student[0].size() - 1; k > -1 && i != j; k--) {
				if (student[i][k] == student[j][k] )
					index++;
				else
					break;
			}
			erase = max(erase, index);
			//cout << student[i] << " " << student[j] << " " << erase << "\n";
		}

	}

	cout << erase;


}