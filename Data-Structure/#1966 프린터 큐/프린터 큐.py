import sys
t = int(input())

while t > 0:
  n, k = map(int,sys.stdin.readline().split())
  queue = list(map(int,sys.stdin.readline().split()))
  index = list(range(len(queue)))#인덱스
  index[k] = -1#찾아야 되는 인덱스를 따로 표시한다
  
#만약 중요도가 제일 높은데 그것이 찾아야하는 문서이면 출력
#중요도가 더 높은 문서가 있으면 큐 맨 오른쪽으로 옮긴다.
  
  cnt = 0
  while True:
    now = queue[0]
    if now == max(queue):
      cnt += 1
      if index[0] == -1:
        print(cnt)
        break
      else:
        queue.pop(0)
        index.pop(0)
    else:
      queue.append(queue.pop(0))
      index.append(index.pop(0))
  t -= 1
      