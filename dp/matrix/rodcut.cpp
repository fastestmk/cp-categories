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

int dp[MAX];

// Recursive version
// int rodcut(vector<int> &prices, int n){
// 	if(dp[n])
// 		return dp[n];
// 	if(n <= 0)
// 		return 0;

// 	int res = -INF;
// 	for(int i = 1; i <= n; ++i){
// 		res = max(res, prices[i-1]+rodcut(prices, n-i));
// 	}
// 	dp[n] = res;
// 	return res;
// }

// Iterative version
int rodcut(vector<int> &prices, int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			dp[i] = max(dp[i], prices[j-1]+dp[i-j]); // dividing rod into two segments i and n-i
		}
	}
	return dp[n];
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; // length of the rod
    cin >> n;

    vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20};
    cout << rodcut(prices, n) << endl;
}