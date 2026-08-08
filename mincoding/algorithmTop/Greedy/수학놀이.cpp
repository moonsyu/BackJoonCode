#include <iostream>

using namespace std;

/* 큐에 저장할 데이터 구조체 */
struct Data {
    int num;
    int cnt;
};

int front, rear;
Data que[1000000];

/* bfs 방식으로 탐색 */
int bfs(int& a, int& b) {
    que[rear++] = { a, 0 };

	int result = 0;
    while (front < rear) {
		auto [now_num, cnt] = que[front++];

		if (now_num * 2 < b) {
			que[rear++] = { now_num * 2, cnt + 1 };
        } else if (now_num * 2 == b) {
			result = cnt + 1;
            break;
        }

        if (now_num * 10 + 1 < b) {
			que[rear++] = { now_num * 10 + 1, cnt + 1 };
		} else if (now_num * 10 + 1 == b) {
            result = cnt + 1;
            break;
        }
    }

    return result;
}


int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0;
    } else {
        int answer = bfs(a, b);
        cout << (answer ? answer : -1);
    }
}
