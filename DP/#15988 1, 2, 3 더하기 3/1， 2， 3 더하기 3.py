import sys
t = int(input())
while t > 0:
  n = int(sys.stdin.readline())
  dp = [0]*1000001
  dp[0] = 0
  dp[1] = 1
  dp[2] = 2
  dp[3] = 4
  for i in range(4, n+1):
    dp[i] = (dp[i-1]%1000000009 + dp[i-2]%1000000009 + dp[i-3]%1000000009)
  print(dp[n]%1000000009)
  t -= 1
  