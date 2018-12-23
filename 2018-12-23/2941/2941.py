from sys import stdin

words = stdin.readline()

chWords = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
result = 0
for i in range(0, 8):
	result += words.count(chWords[i])


print(len(words)-result*2 - 1+result)
	