#include <iostream>
#include <set>

using namespace std;

struct cmp {
	bool operator()(const string& a, const string& b) const {
		if (a.length() == b.length()) {
			return a < b;
		}
		
		return a.length() < b.length();
	}
};

int main() {
	int tc;
	cin >> tc;
	
	
	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;

		set<string, cmp> name_set;
		for (int j = 0; j < n; j++) {
			string name;
			cin >> name;

			name_set.insert(name);
		}

		cout << "#" << i + 1 << "\n";
		for (string name : name_set) {
			cout << name << "\n";
		}
	}
}