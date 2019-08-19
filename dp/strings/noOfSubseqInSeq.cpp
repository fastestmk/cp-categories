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


int distinctSubseq(string str, string pattern){
    int m = str.size();
    int n = pattern.size();
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; ++i){ // when string is empty
        dp[0][i] = 0;
    }

    for(int i = 0; i < m; ++i){ // when patter is empty
        dp[i][0] = 1;
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(str[i-1] == pattern[j-1]){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]; 
                // cout << i << " " << j  << " " <<dp[i][j] << endl; 
            }
            else{
                dp[i][j] = dp[i-1][j];
                // cout << i << " " << j  << " " <<dp[i][j] << endl; 
            }
        }
    }

    return dp[m][n];
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str, pattern;
    cin >> str >> pattern;

    cout << distinctSubseq(str, pattern) << endl;
}
