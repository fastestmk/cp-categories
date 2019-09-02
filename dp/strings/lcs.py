def lcs(s, t):
	m = len(s)
	n = len(t)
	dp = [[0]*(n+1) for i in range(m+1)]
	for i in range(1, m+1):
		for j in range(1, n+1):
			if s[i-1] == t[j-1]:
				dp[i][j] = dp[i-1][j-1]+1
			else:
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
	# return dp[m][n]

	i, j = m, n
	ans = ""
	# iterating in reverse
	while i and j: # 
		if s[i-1] == t[j-1]:
			ans = s[i-1]+ans # concatinating previous element into last string
			i -= 1 
			j -= 1
			continue
		if dp[i-1][j] > dp[i][j-1]:
			i -= 1
		else:
			j -= 1
	print(ans)		

if __name__ == '__main__':
	s = str(input())
	t = str(input())
	print(lcs(s,t))					
