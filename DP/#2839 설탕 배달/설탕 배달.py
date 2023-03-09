import sys
input = sys.stdin.readline

def solve(n) -> int:
  dp = [10001]*(n+1)
  sugar = [3, 5]

  dp[0] = 0
  for i in sugar:
    for j in range(i, n+1):
      if dp[j - i] < 0:
        break
      else:
        dp[j] = min(dp[j], dp[j - i] + 1)

  return dp[n] if dp[n] != 10001 else -1

if __name__ == '__main__':
  n = int(input())
  
  print(solve(n))