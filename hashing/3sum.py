def threeSum(arr, sum):
	n = len(arr)
	hash = dict()
	for i, a in enumerate(arr):
		hash[a] = i

	for i in range(n-1):
		for j in range(i+1, n):
			val = sum-(arr[i]+arr[j])
			if val in hash:
				if hash[val] != i and hash[val] != j:
					print(val, arr[i], arr[j])
					return True
	return False

if __name__ == '__main__':
	arr = list(map(int, input().split()))
	sum = int(input())
	if(threeSum(arr, sum)):
		print("triple exist")											
	else:
		print("not exist")