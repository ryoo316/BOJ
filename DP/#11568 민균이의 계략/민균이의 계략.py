import bisect
n = int(input())
port = list(map(int,input().split()))
dp = [port[0]]
for i in range(n):
  if port[i] > dp[-1]:#현재 원소가 이전 원소보다 크면 dp에 추가
    dp.append(port[i])
  else:
    index = bisect.bisect_left(dp, port[i])
    dp[index] = port[i]
print(len(dp))