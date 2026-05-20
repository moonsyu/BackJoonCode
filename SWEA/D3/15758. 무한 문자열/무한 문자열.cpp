#include <iostream>
#include <string>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string str, text;
		cin >> str >> text;

		string temp1 = "";
		for (int i = 0; i < text.size(); i++) {
			temp1 += str;
		}

		string temp2 = "";
		for (int i = 0; i < str.size(); i++) {
			temp2 += text;
		}

		cout << "#" << t << " ";
		if (temp1 == temp2) {
			cout << "yes";
		} else {
			cout << "no";
		}
		cout << "\n";
	}
}