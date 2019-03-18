n = int(input())
nums = [list(map(int,input().split())) for _ in range(n)]
for y in range(1,n):
	for x in range(len(nums[y])):
		d = []
		if x != len(nums[y])-1:
			d.append(nums[y-1][x])
		if x != 0:
			d.append(nums[y-1][x-1])
		nums[y][x] += max(d)
print(max(nums[-1]))
