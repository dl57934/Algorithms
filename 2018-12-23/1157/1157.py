from sys import stdin 

words = stdin.readline().upper()
result = [0 for i in range(0, 26)]

for i in range(0, 26):
	result[i] = words.count(chr(i+65))

maxNum = max(result)

if(result.count(maxNum) >1):
	print("?")
else:
	print(chr(result.index(maxNum)+65))		
