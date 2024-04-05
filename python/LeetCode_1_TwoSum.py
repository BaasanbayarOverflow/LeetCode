def twoSum(nums, target: int):
	visited = {}
	for i in range(len(nums)):
		diff = target - nums[i]
		if (diff in visited):
			return [visited[diff], i]
		
		visited[nums[i]] = i

	return [-1, -1]


twoSum([3,2,4], 6)