result =0
for i in input():
	result += (ord(i)%65)//3+3
	if i == 'X' or i == 'V' or i == 'Y' or i == 'Z':
		result-=1

print(result)		