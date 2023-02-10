n, k = map(int,input().split())
dp = [0]*(k+1)
dp[0] = 1# 0원을 만들수 있는 경우 = 1가지
coin = sorted([int(input()) for _ in range(n)])

for i in range(n):
  for j in range(coin[i],k+1):
    dp[j] = dp[j] + dp[j-coin[i]]


print(dp[k])
