import sys
t = int(input())

while t > 0:
  n = int(sys.stdin.readline())
  dp = [0 for _ in range(n + 3)]
  dp[1] = 1
  dp[2] = 1
  dp[3] = 1
  
  for i in range(3,n+1):
    dp[i] = dp[i-2] + dp[i-3];
  print(dp[n])
  t -= 1