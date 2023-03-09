import sys
input = sys.stdin.readline
memo = [[[0 for _ in range(102)] for _ in range(102)] for _ in range(102)]

def solution(a, b, c) -> int:
  if memo[a][b][c]:
    return memo[a][b][c]
  if a <= 0 or b <= 0 or c <= 0:
    return 1
  elif a > 20 or b > 20 or c > 20:
    return solution(20, 20, 20)
  elif a < b and b < c:
    memo[a][b][c] = solution(a, b, c-1) + solution(a, b-1, c-1) - solution(a, b-1, c)
    return memo[a][b][c]
  else:
    memo[a][b][c] = solution(a-1, b, c) + solution(a-1, b-1, c) + solution(a-1, b, c-1) - solution(a-1, b-1, c-1)
    return memo[a][b][c]
    
while True:
  a, b, c = map(int,input().split())
  if a == -1 and b == -1 and c == -1:
    break
  else:
    print('w({}, {}, {}) = {}'.format(a,b,c,solution(a, b, c)))