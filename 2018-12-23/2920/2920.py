import sys


arr = list(map(int,sys.stdin.readline().split()))

for i in range(0,7):
	if arr[i]+1 == arr[i+1] :
		result = "ascending"
	elif arr[i] == arr[i+1]+1:	
		result = "descending"
	else:
		result = "mixed"
		break

print(result)			