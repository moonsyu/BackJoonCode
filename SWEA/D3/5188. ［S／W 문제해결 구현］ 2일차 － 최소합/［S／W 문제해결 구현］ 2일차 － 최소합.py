from collections import deque

dx = [0, 1]
dy = [1, 0]

def main():
    tc = int(input().strip())

    for i in range(tc):
        n = int(input().strip())
        square = [list(map(int, input().split())) for _ in range(n)]

        # 방문 표시 및 이동 비용 저장용 2차원 배열
        INF = float('inf')
        dist = [[INF] * n for _ in range(n)]
        
        # 큐 초기화 및 시작점 설정 (시작점의 값, y좌표, x좌표)
        que = deque([(square[0][0], 0, 0)])
        dist[0][0] = square[0][0]
        
        while que:
            sum_val, y, x = que.popleft()

            if dist[y][x] < sum_val:
                continue

            # 이동할 수 있는 방향으로 탐색
            for j in range(len(dx)):
                ny = y + dy[j]
                nx = x + dx[j]

                # 다음 이동할 좌표가 배열의 범위 내에 있는지 유효성 검사
                if 0 <= nx < n and 0 <= ny < n:
                    next_sum = sum_val + square[ny][nx]
                    
                    # 이동 비용 갱신
                    if next_sum < dist[ny][nx]:
                        dist[ny][nx] = next_sum
                        que.append((next_sum, ny, nx))

        print(f"#{i + 1} {dist[n - 1][n - 1]}")

if __name__ == "__main__":
    main()