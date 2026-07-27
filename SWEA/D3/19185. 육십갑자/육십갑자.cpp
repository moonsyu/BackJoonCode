#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;

		vector<string> n_name(n);
		for (int i = 0; i < n; i++) {
			cin >> n_name[i];
		}
		
		vector<string> m_name(m);
		for (int i = 0; i < m; i++) {
			cin >> m_name[i];
		}

		int q;
		cin >> q;

		string answer = "";
		for (int i = 0; i < q; i++) {
			int year;
			cin >> year;

			answer += n_name[(year - 1) % n] + m_name[(year - 1) % m] + " ";
		}

		cout << "#" << t << " " << answer << endl;
	}
}