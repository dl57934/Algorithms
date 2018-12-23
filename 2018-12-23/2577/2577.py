import sys

A = int(sys.stdin.readline())
B = int(sys.stdin.readline())
C = int(sys.stdin.readline())

arr = [0 for i in range(0,10)]

all = A*B*C

startNum = 100000000
for i in range(0, 3):
	if(all >=  startNum):
		break
	startNum//=10;


while(startNum !=1):
	index = all//startNum
	arr[index]+=1
	if(startNum==10):
		arr[all%10]+=1
	all -= index*startNum
	startNum//=10

for i in range(0,10):
	print(arr[i])	

