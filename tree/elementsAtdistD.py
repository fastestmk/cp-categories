from collections import defaultdict

INF =  (10**5)+5
vis = [0]*INF
level = [0]*INF
dp = [0]*INF

tree = defaultdict(list)

def dfs(s):
	vis[s] = 1
	for i in tree[s]:
		if(not vis[i]):
			level[i] = level[s]+1
			if(level[i] == dist):
				print(i, end = " ")
			dfs(i)


if __name__ == '__main__':
	n, dist = [int(i) for i in input().split()]
	for i in range(1, n):
		u, v = [int(i) for i in input().split()]
		tree[u].append(v)
		tree[v].append(u)

	level[1] = 1 # level 1 at root 1
	dfs(1)
	print("")	


