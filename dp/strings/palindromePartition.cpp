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

bool isPalindrome(string str) {
    int left = 0;
    int right = str.size()-1;
    while(left < right) {
        if(str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int minCut(string str) {
    int n = str.size();
    vector<int> dp(n+1);
    dp[n] = -1; // when whole substring is palindrome then res[i] = 1 + res[n] = 1 - 1 = 0 cut
    for(int i=n-1;i>=0;i--) {
        dp[i] = n-i-1; // max size in one cut
        for(int j=i;j<n;j++) {
            if(isPalindrome(str.substr(i, j-i+1))) {
                dp[i] = min(dp[i], 1 + dp[j+1]); // adding one in previous(greater) minimum size
                // cout << i << " " << j-i+1 << " " << dp[i] << endl;
            }
        }
    }
    return dp[0];
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    cout << minCut(str) << endl;
}