
def solve(A, B, C):
	diff = (10**9)+5
	i, j, k = 0, 0, 0
	while(i < len(A) and j < len(B) and k < len(C)):
		low = min(min(A[i], B[j]), C[k])
		high = max(max(A[i], B[j]), C[k])

		diff = min(diff, high-low)

		if A[i] == low:
			i += 1
		elif B[j] == low:
			j += 1
		else:	
			k += 1
	return diff				



A = [int(i) for i in input().split()] #[3, 6, 8, 10, 15]
B = [int(i) for i in input().split()] #[1, 5, 12]
C = [int(i) for i in input().split()] #[4, 8, 15, 16]
print(solve(A, B, C))