import heapq
import sys
input = sys.stdin.readline
n = int(input().strip())
heap = []
for i in range(n):
  c = int(input().strip())
  if c != 0:
    heapq.heappush(heap, c)
  else:
    if heap:
      print(heapq.heappop(heap))
    else:
      print(0)
