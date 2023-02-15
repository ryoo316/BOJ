queue = []
import sys
n, k = map(int,sys.stdin.readline().split())
for i in range(1,n+1):
  queue.append(i)
print('<',end='')
for i in range(1,n):
  for j in range(1,k):
    q = queue.pop(0)
    queue.append(q)
  print(queue.pop(0),end=', ',sep='')
print(queue.pop(0),'>',sep='')
