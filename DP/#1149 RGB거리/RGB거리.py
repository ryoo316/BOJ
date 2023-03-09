import sys
input = sys.stdin.readline

n = int(input())
dp = [list(map(int,input().split())) for _ in range(n)]

def solution(n, dp) -> int:
  for i in range(1,n):
    dp[i][0] += min(dp[i-1][1], dp[i-1][2])
    dp[i][1] += min(dp[i-1][0], dp[i-1][2])
    dp[i][2] += min(dp[i-1][0], dp[i-1][1])
  return min(dp[n-1][0], dp[n-1][1], dp[n-1][2])

print(solution(n, dp))