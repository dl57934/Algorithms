from sys import stdin

N = int(stdin.readline())
floor = 1;

while (N-floor>0):
	N-=floor
	floor+=1

if floor%2==0:
	print("%d/%d" %( N,floor-N+1))
else:
	print("%d/%d" %(floor-N+1, N))