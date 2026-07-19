#include <iostream>
#include <string>
#include <vector>

using namespace std;


/* 당첨 여부 조회 */
long long same(vector<pair<string, long long>>& num, string ticket) {
    for (int i = 0; i < num.size(); i++) {
        
        // ticket과 복권번호 비교
        bool same_ticket = num[i].first.size() ? true : false;
        for (int j = 0; j < num[i].first.size(); j++) {
            if (num[i].first[j] != ticket[j] && num[i].first[j] != '*') {
                same_ticket = false;
                break;
            }
        }

        if (same_ticket) {
            return num[i].second;
        }
    }

    return 0;
}


int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        int n, m;
        cin >> n >> m;

        // {복권 번호, 당첨금}
        vector<pair<string, long long>> num(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i].first >> num[i].second;
        }

        long long answer = 0;
        for (int i = 0; i < m; i++) {
            string ticket;
            cin >> ticket;
            
            answer += same(num, ticket);
        }

        cout << "#" << t << " " << answer << "\n";
    }
}