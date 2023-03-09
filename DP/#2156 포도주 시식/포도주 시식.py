import sys
input = sys.stdin.readline
grape = []
n = int(input().strip())
for i in range(n):
  v = int(input().strip())
  grape.append(v)

dp = [0]*10001
def solution(n, grape):
  if n == 1:
    return grape[0]
  elif n == 2:
    return grape[0] + grape[1]
  dp[0] = grape[0]
  dp[1] = grape[0] + grape[1]
  dp[2] = max(grape[0] + grape[1], grape[1] + grape[2],                  grape[0] + grape[2])
  for i in range(3,n):
    dp[i] = max(dp[i-3] + grape[i-1] + grape[i],                           dp[i-2] + grape[i], dp[i-1])
  return dp[n-1]
  
print(solution(n, grape))
# 6 10 13 9 8 1
