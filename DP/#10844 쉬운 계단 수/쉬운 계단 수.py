import sys
input = sys.stdin.readline

n = int(input())
dp = [[0]* 11 for _ in range(n+1)]

Mod = 1000000000

def solution(n) -> int:
  ans = 0
  for i in range(1,10):
    dp[1][i] = 1
  for i in range(2,n+1):
    for j in range(0,10):
      if j == 0:
        dp[i][j] = dp[i-1][j+1]%Mod
      elif j == 9:
        dp[i][j] = dp[i-1][j-1]%Mod
      else:
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%Mod
  for i in range(0,10):
    ans += dp[n][i]
  return ans

print(solution(n)%Mod)