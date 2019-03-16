from sys import stdin

def LCM(A, B, GSD):
	return (A*B)/GSD

def GSD(A, B):
	if B == 0:
		return A
	return GSD(B, A%B)


A, B = map(int, stdin.readline().split())

if (B > A):
	temp = A
	A = B
	B = temp


print(int (LCM(A, B, GSD(A, B))))

