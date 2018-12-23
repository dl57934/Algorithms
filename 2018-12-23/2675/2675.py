from sys import stdin

T = int(stdin.readline())

for i in range(0, T):
	R, inputData = stdin.readline().split()
	for s in range(0, len(inputData)):
		for r in range(0, int(R)):
			print(inputData[s], end='')
	print()		