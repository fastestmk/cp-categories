from bisect import bisect_right

INF = 10**(9)
def LIS(seq):
	n = len(seq)
	dp = [INF]*(n+1)
	dp[0] = -INF
	for i in range(n):
		j = bisect_right(dp, seq[i]) # similar to upper_bound
		if dp[j-1] < seq[i] and seq[i] < dp[j]:
			dp[j] = seq[i]

	ans = 0
	for i in range(n+1):
		if dp[i] < INF:
			print(dp[i], end = " ")
			ans = i
	return ans

seq = list(map(int, input().split()))
print(LIS(seq))				

