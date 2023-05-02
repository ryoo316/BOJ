import sys
import heapq
input = sys.stdin.readline

INF = int(1e9 + 7)

dx = [-1,0,1,0]
dy = [0,-1,0,1]

def Dijkstra(sx, sy):
    D = [[INF for j in range(w)] for i in range(h)]
    Q = []
    D[sx][sy] = 0
    heapq.heappush(Q, (0, sx, sy))
    while Q:
        cur_door_cnt, x, y = heapq.heappop(Q)
        if D[x][y] < cur_door_cnt:
            continue
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            next_door_cnt = cur_door_cnt
            if nx < 0 or ny < 0 or nx >= h or ny >= w:
                continue
            if V[nx][ny] == '*':
                continue
            if V[nx][ny] == '#':
                next_door_cnt += 1
            if D[nx][ny] > next_door_cnt:
                D[nx][ny] = next_door_cnt
                heapq.heappush(Q, (D[nx][ny], nx, ny))
    return D

def Solve():
    global h, w, V
    h, w = map(int, input().split())
    V = [list(input().rstrip()) for _ in range(h)]
    for i in range(h):
        V[i] = ['.'] + V[i] + ['.']
    h += 2
    w += 2
    V = [['.'] * w] + V + [['.'] * w]
    """
    for i in range(h):
        for j in range(w):
            print(V[i][j], end='')
        print()
    """
    x1 = y1 = x2 = y2 = INF
    for i in range(h):
        for j in range(w):
            if V[i][j] == '$':
                if x1 == INF and y1 == INF:
                    x1 = i
                    y1 = j
                else:
                    x2 = i
                    y2 = j
    D1 = Dijkstra(0, 0)
    D2 = Dijkstra(x1, y1)
    D3 = Dijkstra(x2, y2)
    ans = INF
    for i in range(h):
        for j in range(w):
            if D1[i][j] == INF:
                continue
            sum = D1[i][j] + D2[i][j] + D3[i][j]
            if V[i][j] == '#':
                sum -= 2
            ans = min(ans, sum)
    return ans

if __name__ == "__main__":
    T = int(input())
    while T:
        print(Solve())
        T -= 1