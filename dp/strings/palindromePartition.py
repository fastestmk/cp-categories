def minCut(s):
	cut = [x for x in range(-1, len(s))]
	# print(cut[0])
	for i in range(len(s)):
		for j in range(i, len(s)):
			if s[i:j] == s[j:i:-1]:
				print(s[i:j], s[j:i:-1])
				cut[j+1] = min(cut[j+1], cut[i]+1)
	return cut[-1]

if __name__ == '__main__':
	s = str(input())
	print(minCut(s))				