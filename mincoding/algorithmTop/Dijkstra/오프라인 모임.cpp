/*
* 각 학생들이 p 마을까지 가는 최단 경로 및
* p 마을에서 각 학생들이 집으로 돌아가는 최단 경로를 구한 후
* 두 경로의 합이 가장 큰 학생을 찾아 시간을 구하는 문제
*
* --- 조건 ---
* 1. 단방향 그래프
*
*
* --- 키 포인트 ---
* 1. p 마을을 중심으로 탐색을 진행한다
* 2. 각 학생 -> p 마을 까지 가는 최단 경로를 구할 때
*    p 마을에서 각 학생까지로 방향을 바꿔서 탐색을 진행한다
* 3. p 마을 -> 각 학생까지 가는 최단 경로를 구할 때
*    입력 경로 그대로 탐색을 진행한다
*
* --- 풀이 ---
* 1. struct Edge 정의 (int dest, weight)
* 2. vector<vector<Edge>> graph, reverse_graph 정의
* 3. total_cost로 각 노드별 현재 도착 비용 저장용 배열 정의
* 4. student에 각 학생 별 이동 비용 저장용 배열 정의
* 5. edge 정보 입력받을 때, graph에는 입력 그대로, reverse_graph에는 방향을 반대로 저장
* 6. dijkstra 함수 정의 (vector<vector<Edge>>& graph)
*	ㄴ pq로 사용할 배열 및 compare 구조체 정의 (cost 기준 오름차순)
*	ㄴ pq에 넣을 데이터 구조체 정의 (int node, int cost)
*	ㄴ pq[rear++] = {p, 0};
*	ㄴ auto [now_node, now_cost] = pq[front++];
*	ㄴ for (auto [dest_node, dest_cost] : graph[now_node])
*	ㄴ int next_cost = now_cost + dest_cost;
*	ㄴ if (total_cost[dest_node] == -1 || total_cost[dest_node] > next_cost) {
*	ㄴ total_cost[dest_node] = next_cost;
*	ㄴ pq[rear++] = {dest_node, next_cost};
* 7. dijkstra 함수 호출 (reverse_graph)
* 8. student 배열에 각 학생의 이동 비용 저장
* 9. total_cost 배열 초기화 (-1로)
* 10. dijkstra 함수 호출 (graph)
* 11. student 배열에 각 학생의 이동 비용 저장하며 최대 값 탐색
* 12. 최대값 출력
*
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선 정보 구조체
struct Edge {
	int dest, cost;
};

// 간선 정보 저장
vector<vector<Edge>> graph(10002), reverse_graph(10002);

// pq 데이터 구조체
struct MV_Data {
	int node, cost;
};

// pq 정렬용 구조체
struct compare {
	bool operator()(MV_Data& md1, MV_Data& md2) {
		return md1.cost < md2.cost;
	}
};

// pq 선언
int front, rear;
MV_Data pq[1000000];

// 각 노드별 현재 도착 비용 저장용 배열
long long total_cost[10002];

// 각 학생 별 이동 비용 저장용 배열
long long student[10002];

int n, m, p;

/* 입출력 최적화 */
void optimize_io() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
}


/* 간선 정보 입력 */
void input() {
	cin >> n >> m >> p;
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({ e, w });
		reverse_graph[e].push_back({ s, w });
	}
}


/* node간 이동 비용 기록 초기화 */
void reset_total_cost() {
	for (int i = 1; i <= n; i++) {
		total_cost[i] = -1;
	}
}


/* 이동 비용 계산 */
void dijkstra(vector<vector<Edge>>& now_graph) {
	// 각 노드별 도착 비용 초기화
	reset_total_cost();
	total_cost[p] = 0;

	front = rear = 0;
	pq[rear++] = { p, 0 };
	while (front < rear) {
		// 현재 노드와 사용 비용 pop
		auto [now_node, now_cost] = pq[front++];

		// 현재 노드에서 갈 수 있는 노드 탐색
		for (auto [dest_node, dest_cost] : now_graph[now_node]) {

			// 노드 미방문 혹은 현재 비용보다 더 적은 비용으로 도착할 수 있는 경우
			// 방문 비용 업데이트 및 pq에 push
			int next_cost = now_cost + dest_cost;
			if (total_cost[dest_node] == -1 || total_cost[dest_node] > next_cost) {
				total_cost[dest_node] = next_cost;
				pq[rear++] = { dest_node, next_cost };
			}
		}

		sort(pq + front, pq + rear, compare());
	}
}


/* 학생들의 이동 비용 업데이트 */
void student_update() {
	for (int i = 1; i <= n; i++) {
		student[i] += total_cost[i];
	}
}


/* 학생들 중 이동 비용이 가장 높은 값 반환 */
long long get_max_student_cost() {
	long long result = 0;
	for (int i = 1; i <= n; i++) {
		if (student[i] + total_cost[i] > result) {
			result = student[i] + total_cost[i];
		}
	}

	return result;
}


int main() {

	optimize_io();
	input();
	dijkstra(reverse_graph);
	student_update();
	dijkstra(graph);
	cout << get_max_student_cost() << "\n";
}
