import sys
input = sys.stdin.readline
MOD = 999999999999
def solution() -> int:
  dp = [[0]*3 for _ in range(n)]
  ans = MOD
  for k in range(3):
    #색 정하기
    for i in range(3):
      #예제 입력 1
      #ex) 26 MOD MOD, MOD 40 MOD, MOD MOD 83
      if i == k: #색을 정해준다.
        dp[0][i] = arr[0][i]
      else:      #다른건 큰값으로 해준다.(이 색을 선택하면 안되니)
        dp[0][i] = MOD
    #계산
    for i in range(1,n):
      dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0]
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1]
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2]
    #최소값 갱신
    for i in range(3):
      if i == k:#i == k면 continue(처음과 끝이 같은색이면 안되니)
        continue
      ans = min(ans, dp[n-1][i])
  return ans
  
if __name__ == "__main__":
  #입력
  n = int(input())
  arr = [list(map(int, input().split())) for _ in range(n)]
  #답 출력
  print(solution())