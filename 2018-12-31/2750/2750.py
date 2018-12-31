from sys import stdin

N = int(stdin.readline())

arr = [0 for i in range(0, N)]

for i in range(0, N):
	arr[i] = int(stdin.readline())	

arr.sort()

for i in range(0, N):
	print(arr[i])