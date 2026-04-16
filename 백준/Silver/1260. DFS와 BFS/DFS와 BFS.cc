#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void dfs(vector<int> &visit, vector<vector<int>> &dfs_bfs, int v) {
	if (visit[v] == 0) {// 방문하지 않은 정점일 경우 실행
		cout << v << " ";// 방문한 정점 출력
		visit[v] = 1;// 방문한 표시
		
		for (int i = 0; i < dfs_bfs[v].size(); i++) // 간선 개수만큼 파고드는 반복문
			dfs(visit, dfs_bfs, dfs_bfs[v][i]); // 연결된 간선의 끝으로 향하게 바로 함수 선언 
	}
}

void bfs(vector<int>& visit, vector<vector<int>>& dfs_bfs, queue<int> &que, int v) {

	while (!que.empty()) {
		v = que.front();
		if (visit[v] == 0) {
			cout << v << " ";
			visit[v] = 1;
			for (int i = 0; i < dfs_bfs[v].size(); i++) {
				if (visit[dfs_bfs[v][i]] == 0)// bfs는 dfs와 달리 지나간곳을 간선을 통해 또 갈수도 있기에 안지나간 곳만 push하게 선언
					que.push(dfs_bfs[v][i]);
			}
		}
		que.pop(); // 다음 순서의 정점을 파악하기 위해 먼저 지나간 정점 삭제
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, v, a, b;

	cin >> n >> m >> v;

	vector<vector<int>> dfs_bfs(n + 1); //┐
	vector<int> visit(n + 1, 0); // ㅡㅡㅡㅡ 정점의 수가 1부터 시작하기에 n + 1을 하여 배열의 크기 증가
	queue<int> que;

	for (int i = 0; i < m; i++) {// 간선 생성 2차원 배열로 선언하여 1과 2를 연결할때 [1][0] = 2 가되는방식
		cin >> a >> b;
		dfs_bfs[a].push_back(b);
		dfs_bfs[b].push_back(a);
	}

	for (int i = 0; i <= n; i++)// 전체적인 순서가 아닌 각 정점과 연결되어 있는 정점을 작은순으로 가게끔 재배치 한 코드
		stable_sort(dfs_bfs[i].begin(), dfs_bfs[i].end());

	dfs(visit, dfs_bfs, v);
	
	for (int i = 0; i < n + 1; i++) // dfs에서 방문했던값을 없애고 방문하지 않은것처럼 초기화
		visit[i] = 0;

	cout << "\n";// dfs, bfs의 출력을 구분하기 위한 띄우기
	que.push(v);// 정점의 출발점을 que에 입력
	bfs(visit, dfs_bfs, que, v);
}