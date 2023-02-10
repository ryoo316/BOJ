n, k = map(int,input().split())
dp = [10001]*(k+1)
dp[0] = 0
coin = sorted([int(input()) for _ in range(n)])

for i in range(n):
  for j in range(coin[i],k+1):
    if dp[j-coin[i]] < 0:
      break
    else:
      dp[j] = min(dp[j], dp[j-coin[i]] + 1)

if dp[k] == 10001:
  print(-1)
else:
  print(dp[k])
