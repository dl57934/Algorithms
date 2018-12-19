N = int(input())

str1 = ""
str2 = ""

for i in range(0, N):
	str1 += "*"
	str2 += str1+"\n"

print(str2)