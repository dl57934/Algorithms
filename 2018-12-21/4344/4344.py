import sys

N = int(sys.stdin.readline())

for i in range(0, N):
	score = list(map(int, sys.stdin.readline().split()))
	sumScore = sum(score[1:])
	avg = sumScore/score[0]
	filterScore = [i for i in score[1:] if i>avg]
	print("%.3f%%"%(len(filterScore)/score[0]*100))

	