from collections import deque
d = deque([])
import sys
n, k = map(int,sys.stdin.readline().split())
for i in range(1,n+1):
  d.append(i)
print('<',end='')
for i in range(1,n):
  for j in range(1,k):
    q = d.popleft()
    d.append(q)
  print(d.popleft(),end=', ',sep='')
print(d.popleft(),'>',sep='')
