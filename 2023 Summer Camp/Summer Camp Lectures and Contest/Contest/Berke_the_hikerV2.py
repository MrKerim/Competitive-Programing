import heapq

n, m = map(int, input().split())

INF = float('inf')
dp = [[INF] * m for _ in range(n)]

matrice = [list(map(int, input().split())) for _ in range(n)]
sr, sc = map(int, input().split())
er, ec = map(int, input().split())
er = er-1
ec = ec -1
dp[sr - 1][sc - 1] = 0

def Dijkstra(matrice, sr, sc):
    min_heap = [(0, sr - 1, sc - 1)]
    heapq.heapify(min_heap)

    while min_heap:
        cost, r, c = heapq.heappop(min_heap)

        if(r==er and c == ec):
            print(cost)
            exit()

        neighbors = [
            (r - 1, c),
            (r, c - 1),
            (r + 1, c),
            (r, c + 1)
        ]

        for nr, nc in neighbors:
            if 0 <= nr < n and 0 <= nc < m and matrice[nr][nc] != 0:
                node_cost = abs(matrice[nr][nc] - matrice[r][c])
                new_cost = cost + node_cost
                if new_cost < dp[nr][nc]:
                    dp[nr][nc] = new_cost
                    heapq.heappush(min_heap, (new_cost, nr, nc))

    return dp

print(Dijkstra(matrice, sr, sc)[er][ec])
