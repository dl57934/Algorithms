from sys import stdin 

N = int(stdin.readline())
between=1
floor=1
while(True):
	if N <= between:
		print(floor)
		break
	between+=6*floor
	floor+=1	

