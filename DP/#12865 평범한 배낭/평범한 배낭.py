n, k = map(int,input().split())
def solution(n,k) -> int:
  dp = [0]*(k+1)
  for i in range(n):
    w, v = map(int,input().split())
    if w > k:
      continue
    for j in range(k,0,-1):#k부터
      if j + w <= k and dp[j] != 0:
        dp[j+w] = max(dp[j+w], dp[j] + v)
    dp[w] = max(dp[w], v)
  return max(dp)
      
print(solution(n,k))