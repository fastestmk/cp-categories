#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;
int m, n;
int dp[10][10];
int matrix[10][10];
// vector<vector<int> > matrix(4, vector<int>(4));



int minCostPath(int m, int n){
	if(dp[m][n])
		return dp[m][n];
	if(m < 0 || n < 0)
		return MAX;
	if(m == 0 && n == 0)
		return matrix[m][n];
	int res = matrix[m][n]+min({minCostPath(m-1, n-1), minCostPath(m-1, n), 
								 minCostPath(m, n-1)}); //  You can only traverse down, right and diagonally lower cells from a given cell,
	dp[m][n] = res;
	// cout << res << endl;
	return res;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> m >> n;
    //vector<vector<int> > matrix(m, vector<int>(n));
    
    for(int i = 0; i < m; ++i){
    	for(int j = 0; j < n; ++j){
    		cin >> matrix[i][j];
    	}
    }
    // memset(dp, -1, sizeof(dp));
    cout << minCostPath(m-1, n-1) << endl;
}