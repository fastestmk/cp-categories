def sol(arr, m):
	n = len(arr)
	left, count, window, leftInd = 0, 0, 0, 0

	for right in range(n):
		if arr[right] == 0:
			count += 1
		while count > m:
			if arr[left] == 0:
				count -= 1
			left += 1
		if right-left+1 > window:
			window = right-left+1
			leftInd = left
	return list(range(leftInd, leftInd+window))
	# print(leftInd, end = " ")
	# print(leftInd+window-1)

if __name__  == "__main__":
	arr = [int(i) for i in input().split()]#[1, 1, 0, 1, 1, 0, 0, 1, 1, 1]
	m = int(input()) # max no of flips 

	s = sol(arr, m)
	print(s)
						
