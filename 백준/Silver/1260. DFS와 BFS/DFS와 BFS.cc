#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void dfs(vector<vector<int>>& graph, vector<bool>& visit, int now) {
	
	visit[now] = false;
	cout << now << " ";

	for (int i = 0; i < graph[now].size(); i++) {
		if (visit[graph[now][i]]) {
			dfs(graph, visit, graph[now][i]);
		}
	}
}


void bfs(vector<vector<int>>& graph, int start) {
	queue<int> que;
	que.push(start);

	vector<bool> visit(graph.size(), true);
	visit[start] = false;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		cout << now << " ";

		for (int i = 0; i < graph[now].size(); i++) {
			if (visit[graph[now][i]]) {
				visit[graph[now][i]] = false;
				que.push(graph[now][i]);
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	/**
	* 간선을 입력받아 BFS와 DFS로 탐색한 결과를 출력하라
	* 
	* -- 자연어 풀이 --
	* 1. n, m, v를 입력받는다
	* 2. n의 크기를 가진 2차원 vector와 방문 확인용 n * n vector를 선언한다
	* 3. m개의 간선을 입력 받아 2차원 vector에 저장한다
	*    ㄴ ex) 0 1 입력 -> vector[0].push_back(1), vector[1].push_back(0)
	* 4. 시작점(v)를 시작으로 dfs 방식으로 탐색한다
	*    ㄴ 1. 함수의 인자는 (vector, visit, now)를 사용한다
	*    ㄴ 2. visit[now][i] == true 라면 
	*    ㄴ 3. visit[now][i] = false로 바꿔주고, 
	*	 ㄴ 4. visit[now][i]를 출력 후, 
	*	 ㄴ 5. dfs(vector, visit, vector[now][i])를 호출한다
	* 5. 시작점(v)를 시작으로 bfs 방식으로 탐색한다
	*    ㄴ 1. 함수의 인자는 (vector, visit, now)를 사용한다
	*    ㄴ 2. visit[now][i] == true 라면
	*    ㄴ 3. visit[now][i] = false로 바꿔주고,
	*	 ㄴ 4. visit[now][i]를 출력 후,
	*    ㄴ 5. queue에 vector[now][i]를 저장한다
	*    ㄴ 6. queue가 빌 때까지 2~5번을 반복한다
	* 
	* -- 추가 수정 사항 --
	* 1. dfs에 prev 인자를 추가하여, 이전 노드로 돌아가는 경우 방지 xx
	* 2. dfs에서 간선의 방문 확인을 양쪽에 체크
	*    ㄴ visit[now][graph[now][i]] = visit[graph[now][i]][now] = false;
	* 3. visit을 1차원 vector로 변환
	*    ㄴ 간선이 아닌 정점의 방문 여부를 체크
	* 4. 정점 번호가 작은것 부터 우선 방문
	*/

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> graph(n + 1);
	vector<bool> visit(graph.size(), true);
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (vector<int>& v : graph) {
		sort(v.begin(), v.end());
	}

	dfs(graph, visit, v);
	cout << "\n";
	bfs(graph, v);
}