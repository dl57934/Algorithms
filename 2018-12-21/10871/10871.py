import sys 

N, X = map(int, sys.stdin.readline().split())
answer = [x for x in input().split() if int(x) < X]


print(' '.join(answer))