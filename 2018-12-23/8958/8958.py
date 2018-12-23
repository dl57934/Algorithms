# import sys

# N = int(sys.stdin.readline())

# result = [0 for i in range(0, 100)]

# for i in range(0, N):
# 	last = 0
# 	OX = sys.stdin.readline()
# 	for j in range(0, len(OX)-1):
# 		if(OX[j]=="X"):
# 			last=0
# 		else:
# 			last+=1
# 			result[i] += last	

# for i in range(0,N):
# 	print(result[i])

#1등 코드

from sys import stdin
for _ in range(int(stdin.readline())):
    print(sum(sum(range(1, len(i+1))) for i in stdin.readline().strip().split("X")))	