import sys
input = sys.stdin.readline

n = int(input())
dp = [list(map(int,input().split())) for _ in range(n)]

def solution(n, dp) -> int:
  if n == 1:
    return dp[0][0]
  Max = -1
  for i in range(n):
    if i == 0:
      continue
    for j in range(i+1):
      if j == 0:
        dp[i][j] += dp[i-1][j]
      elif j == i:
        dp[i][j] += dp[i-1][j-1]
      else:
        dp[i][j] += max(dp[i-1][j-1], dp[i-1][j])
      if Max < dp[n-1][j]:
        Max = dp[n-1][j]
  return Max
        
print(solution(n, dp))