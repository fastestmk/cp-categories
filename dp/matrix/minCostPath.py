import sys
dp = [[0]*1234]*1234

def min(a, b, c):
	if(a < b):
		return a if a < c else c
	else:
		return b if b < c else c	

def solve(matrix, m, n):
	if dp[m][n]:
		return dp[m][n]

	if m < 0 or n < 0:
		return sys.maxsize	

	if m == 0 and n == 0:
		return matrix[m][n]		
	
	res = matrix[m][n] + min(solve(matrix, m, n-1), solve(matrix, m-1, n), solve(matrix, m-1, n-1))

	dp[m][n] = res
	return res

def minCostPath(matrix):
	m = len(matrix)
	n = len(matrix[0])
	return solve(matrix, m-1, n-1)

if __name__ == '__main__':
	# matrix = []
	# for i in range(3):
	# 	matrix.append([int(j) for j in input().split()])
	matrix = [[int(j) for j in input().split()] for i in range(3)]
	print(minCostPath(matrix)) 	


	

