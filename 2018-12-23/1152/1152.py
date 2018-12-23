import sys
from operator import eq
inputData = sys.stdin.readline().strip()
spaceLength = inputData.count(" ")

if(eq(inputData,"")):
	print(0)
else:	
	print(spaceLength+1)