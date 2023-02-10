import sys
import bisect
input = sys.stdin.readline
n = int(input())
dp = [1]*(n+1)
seq = list(map(int,input().split()))

for i in range(n):
  for j in range(i):
    if seq[i] > seq[j]:
      dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))

max_dp = max(dp)
max_idx = dp.index(max_dp)

ans = []
while max_idx >= 0:
  if dp[max_idx] == max_dp:
    ans.append(seq[max_idx])
    max_dp -= 1
  max_idx -= 1

print(*ans[::-1])