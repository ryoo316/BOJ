n = int(input())
arr = list(map(int,input().split()))
dp = [1]*(n+1)
for i in range(n):
  for j in range(i):
    if arr[i] > arr[j]:#현재 위치보다 이전 원소가 작은지
      dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))