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

int infiniteCoins(vector<int> coins, int sum){
	int n = coins.size();
	dp[0] = 1;
	for(auto coin : coins){
		for(int i = coin; i <= sum; ++i){
			if(i-coin >= 0){
				dp[i] += dp[i-coin];
			}
		}
	}
	return dp[sum];
}

// int infiniteCoins(vector<int> coins, int sum){
// 	if(dp[sum])
// 		return dp[sum];
// 	if(sum < 0)
// 		return 0;
// 	if(sum == 0)
// 		return 1;
// 	int best;
// 	for(auto coin : coins){
// 		best += infiniteCoins(coins, sum-coin);
// 	}
// 	dp[sum] = best;
// 	return best;
// }
int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sum;
    cin >> sum; // 10
    vector<int> coins{2,5,3,6};
    cout << infiniteCoins(coins, sum) << endl;
}