from sys import stdin
inputData = stdin.readline()
for i in range(97, 123):
	print(inputData.find(chr(i)), end=' ')