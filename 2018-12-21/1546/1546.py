import sys

N = int(sys.stdin.readline())

score = [ int(i) for i in sys.stdin.readline().split()]

M = max(score)

score = [ i/M*100 for i in score]
score = sum(score)

print("%.2f"%(score/N))