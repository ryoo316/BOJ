import sys
input = sys.stdin.readline
dp = [0]*1000000
dp[0] = 1
dp[1] = 1

def solution(n) -> int:
  if n > 1:
    for i in range(2,n+1):
      dp[i] = dp[i-1] + 2*dp[i-2]
  return dp[n]

while True:
  try:
    n = int(input().strip())
    print(solution(n))
  except:
    break