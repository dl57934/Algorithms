import sys

N = int(sys.stdin.readline())
 
originalNum = N
count = 0

while(True):
	one = (N//10+N%10)%10
	ten = N%10
	count += 1
	if(ten*10+one == originalNum): break
	N = ten*10+one

print(count)