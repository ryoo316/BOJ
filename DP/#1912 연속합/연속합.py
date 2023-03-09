import sys
input = sys.stdin.readline

n = int(input())
dp = list(map(int,input().split()))

def solution(n, dp) -> int:
  max = dp[0]
  if n == 1:
    return dp[0]
  else:
    for i in range(1,n):
      if dp[i-1] > 0 and dp[i] + dp[i-1] > 0:
        dp[i] = dp[i] + dp[i-1]
      if max < dp[i]:
        max = dp[i]
    return max

print(solution(n, dp))