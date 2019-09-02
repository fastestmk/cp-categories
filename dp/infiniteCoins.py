def infiniteCoins(coins, sum):
	dp = [0]*(10**5) 
	dp[0] = 1
	for c in coins:
		for i in range(c, sum+1):
			if i-c >= 0:
				dp[i] += dp[i-c]
	return dp[sum]
	
if __name__ == '__main__':
	coins = list(map(int, input().split()))
	sum = int(input())
	print(infiniteCoins(coins, sum))				
