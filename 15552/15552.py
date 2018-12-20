# # 내 코드
# import sys

# N = int(sys.stdin.readline())

# for i in range(0, N):
# 	A, B= sys.stdin.readline().split(' ')
# 	print(int(A)+int(B))

# 1등 코드 

from sys import stdin, stdout

input = stdin.readline
print = stdout.write

n = int(input())

for i in range(0, n):
	a, b = map(int, input().split())	
	print("%d\n"%(a+b))