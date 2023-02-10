import sys
input = sys.stdin.readline
n = int(input().strip())
arr = list(map(int,input().split()))
dp1 = [1]*n#앞
dp2 = [1]*n#뒤
def solution(n, arr) -> int:
  for i in range(n):
    for j in range(i):
      if arr[i] > arr[j]:
        dp1[i] = max(dp1[i], dp1[j] + 1)
  for i in range(n-1,-1,-1):
    for j in range(n-1,i,-1):
      if arr[i] > arr[j]:
        dp2[i] = max(dp2[i], dp2[j] + 1)
  Max = 0
  for i in range(n):
    if Max < dp1[i] + dp2[i] - 1:
      Max = dp1[i] + dp2[i] - 1
  return Max

print(solution(n, arr))