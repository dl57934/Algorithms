N = int(input())

result = ""

for i in range(1, 10):
	result += str(N)+" * "+str(i)+" = "+str(N*i)+"\n"

print(result)