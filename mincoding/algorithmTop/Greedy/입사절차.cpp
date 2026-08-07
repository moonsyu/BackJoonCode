#include <iostream>
#include <algorithm>

using namespace std;


struct Applicant {
    int coding;
    int interview;
};


struct coding_compare {
    bool operator() (Applicant a, Applicant b) {
        return a.coding < b.coding;
    }
};

Applicant people[100000];


int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
		cin >> people[i].coding >> people[i].interview;
    }

	sort(people, people + n, coding_compare());

    int answer = 1;
	int now = people[0].interview;
    for (int i = 1; i < n; i++) {
		if (now > people[i].interview) {
            answer++;
            now = people[i].interview;
		}
    }

    cout << answer << "\n";
}
