import sys
input = sys.stdin.readline
n = int(input().strip())
seq = [[0]*2 for _ in range(n)]
for i in range(n):
  seq[i][0], seq[i][1] = map(int,input().split())
seq.sort()
dp = [1]*n
for i in range(n):
  for j in range(i):
    if seq[i][1] > seq[j][1]:
      dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))