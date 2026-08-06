#include <iostream>
#include <algorithm>

using namespace std;


struct player {
    int height;
    int number;

    bool operator() (player p1, player p2) {
		if (p1.height == p2.height) {
			return p1.number < p2.number;
		}
        return p1.height > p2.height;
    }
};


int n;
player player_infos[1000001];

int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> player_infos[i].height;
        }

		for (int i = 0; i < n; i++) {
			cin >> player_infos[i].number;
		}

        sort(player_infos, player_infos + n, player());

        bool answer = true;
        for (int i = 0; i < n && answer; i++) {
            if (player_infos[i].number != i + 1) {
                answer = false;
            }
        }

        cout << (answer ? "YES" : "NO") << "\n";
    }
}
