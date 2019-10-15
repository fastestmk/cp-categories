def noOfWaysToReachEnd(maze):
	m = len(maze)
	n = len(maze[0])

	if maze[0][0] == -1:
		return 0

	for i in range(m):
		if maze[i][0] == 0:
			maze[i][0] = 1
		else:
			break

	for i in range(1, n):
		if maze[0][i] == 0:
			maze[0][i] = 1
		else:
			break

	for i in range(1, m):
		for j in range(1, n):
			if maze[i][j] == -1:
				continue

			if maze[i-1][j] > 0:
				maze[i][j] += maze[i-1][j]

			if maze[i][j-1] > 0:
				maze[i][j] += maze[i][j-1]		

	if maze[m-1][n-1] > 0:
		return maze[m-1][n-1]
	return 0										

if __name__ == '__main__':
	maze = [[int(j) for j in input().split()] for i in range(4)]
	# [[0, 0, 0, 0], [0, -1, 0, 0], [-1, 0, 0, 0], [0, 0, 0, 0 ]]
	print(noOfWaysToReachEnd(maze))	