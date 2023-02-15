import heapq
import sys
input = sys.stdin.readline
n = int(input().strip())
heap = []
for i in range(n):
  c = int(input().strip())
  if c != 0:
    heapq.heappush(heap,(-c,c))
  else:
    if heap:
      print(heapq.heappop(heap)[1])
    else:
      print(0)
