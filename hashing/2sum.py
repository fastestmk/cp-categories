def twosum(arr, sum):
	hash = dict()
	for i, a in enumerate(arr):
		if sum-a in hash:
			return hash[sum-a]+1, i+1
		hash[a] = i
	return []
	
if __name__ == '__main__':
	arr = [int(i) for i in input().split()]
	sum = int(input())
	print(twosum(arr, sum))