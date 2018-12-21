selfNumber = [ 1 for i in range(0, 10038)]

for i in range(1, 9994):
	number = i
	tou = number//1000
	number -= tou*1000
	hun = number//100
	number -= hun*100
	ten = number//10
	one = number%10
	selfNumber[i+tou+hun+ten+one] = 0;

for i in range(1, 9994):
	if(selfNumber[i]== 1):
		print(i)	