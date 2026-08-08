#include <iostream>
#include <algorithm>

using namespace std;

int front, rear;
long long que[10000];


/* 우선 순위 큐 정렬 */
void priority_queue() {
	sort(que + front, que + rear);
}

int main() {

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> que[rear++];
    }

    long long answer = 0;
    long long weight = 0;
    while (front + 1 < rear) {
		priority_queue();
        que[rear++] = que[front] + que[front + 1];
        answer += que[rear - 1];
        front += 2;
    }

    cout << answer << "\n";
}
