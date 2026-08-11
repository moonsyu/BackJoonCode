/*
* 각 정점간 간선이 주어졌을 때,
* 시작 ~ 도착 정점까지 가는 최단 거리를 구하라
* 
* --- 조건 ---
* 1. 방향 존재
* 
* --- 풀이 ---
* 1. 도착지, 비용, 방문 비용 구조체 Node 생성
* 2. vector<vector<Node>> graph(20000, vector<Node>(1, {0, 0, -1})) 생성
* 3. que에 시작점 push
* 4. que와 연결된 노드들 탐색
* 4 - 1. 아직 방문하지 않은 노드라면 (방문 비용 == -1)
*        해당 노드의 방문 비용 = 현재 노드의 방문 비용 + 간선 비용
*		 que.push(해당 노드)
* 4 - 2. 방문한 노드라면 (방문 비용 != -1)
*        방문 비용 효율 계산
*        ㄴ 해당 노드의 방문 비용 > 현재 노드의 방문 비용 + 간선 비용
*           ㄴ해당 노드의 방문 비용 = 현재 노드의 방문 비용 + 간선 비용
*			ㄴ que.push(해당 노드)
*		 ㄴ 해당 노드의 방문 비용 <= 현재 노드의 방문 비용 + 간선 비용
*           ㄴ continue;
* 5. que가 빌 때 까지 4. 반복
* 6. graph[도착지][0].cost == -1 이면 impossible 출력
* 7. graph[도착지][0].cost != -1 이면 graph[도착지][0].cost 출력
* 
* 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 정점 정보 구조체
struct Node {
	int dest;
	int cost;
	long long visit_cost;
};

// 정점 및 간선 수
int n, m;

// 정점 및 간선 정보 그래프
vector<vector<Node>> graph(20000, vector<Node>(1, { 0, 0, -1 }));

// 탐색 큐
int front, rear;
int que[100000];



long long bfs(int start) {
	// 시작점 방문 비용 0으로 초기화
	graph[start][0].visit_cost = 0;

	// 시작점 큐에 push
	que[rear++] = start;
	while (front < rear) {
		int node = que[front++];

		// 연결된 노드 탐색
		for (int i = 0; i < graph[node].size(); i++) {
			auto [dest, cost, visit_cost] = graph[node][i];
			bool is_visited = (graph[dest][0].visit_cost != -1);

			// 방문 여부에 따른 처리
			if (!is_visited) {
				graph[dest][0].visit_cost = graph[node][0].visit_cost + cost;
				que[rear++] = dest;
			} else {
				// 방문 비용 효율 계산
				if (graph[dest][0].visit_cost > graph[node][0].visit_cost + cost) {
					graph[dest][0].visit_cost = graph[node][0].visit_cost + cost;
					que[rear++] = dest;
				}
			}
		}
	}

	return graph[n - 1][0].visit_cost;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({e, w, -1});
	}

	cout << (bfs(0) == -1 ? "impossible" : to_string(graph[n - 1][0].visit_cost));
}
