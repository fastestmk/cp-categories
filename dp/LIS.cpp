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

const int INF = 1e9;
const int mod = 1e9+7;
const int MAX = 1e5+5;

int LIS(vector<int> seq){
	int n = seq.size();
	vector<int> dp(n+1, INF);
	dp[0] = -INF;
	for(int i = 0; i < n; ++i){
		int j = upper_bound(dp.begin(), dp.end(), seq[i]) - dp.begin();
		if(dp[j-1] < seq[i] && seq[i] < dp[j]){
			dp[j] = seq[i];
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i){
		if(dp[i] < INF){
			cout << dp[i] << " ";	
			ans = i;
		}
	}
	cout << endl;
	return ans;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sz;
    cin >> sz;
    vector<int> seq(sz);
    for(int i = 0; i < sz; ++i){
    	cin >> seq[i];
    }

    cout << LIS(seq) << endl;
}