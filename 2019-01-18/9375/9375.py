import sys

info = {}
T = int(sys.stdin.readline())

result = 1

for i in range(0, T):
	n = int(sys.stdin.readline())
	for j in range(0, n):
		order = sys.stdin.readline().split()
		if order[1] not in info:
			info[order[1]] = 1
		else: 
			info[order[1]] += 1
	for k in info:	
		result*=(info[k]+1)

	print(result-1)
	result=1
	info.clear()		
		
	