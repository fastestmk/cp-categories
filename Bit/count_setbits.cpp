int solve(int n){
	int count = 0;
	while(n){ 
		n &= (n-1); // turning the rightmost set bit off in every iteration
		count++;
	}
	return count;
}

// __builtin_popcount(n) for shortcut
