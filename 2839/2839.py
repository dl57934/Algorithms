nKgSugar = int(input())

minPerRmd = [0, 6, 12, 3, 9]

rmdIndex = nKgSugar % 5

nKgSugar -= minPerRmd[rmdIndex]

if(nKgSugar < 0):
	result = -1
else :
	result = nKgSugar//5 + 	minPerRmd[rmdIndex]//3

print(result)	