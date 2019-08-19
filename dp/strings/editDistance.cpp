// https://atcoder.jp/contests/dp/tasks/dp_f
#include<iostream>
#include<vector>

using namespace std;

#define ll long long

const int INF = 1e9+5;

int dp[3005][3005];

int min(int x, int y, int z){
    return min(min(x, y), z);   
}

int editDist(string s, string t, int m, int n){
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i==0) 
                dp[i][j] = j;  // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j==0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
                // cout << i << " " << j << " " << dp[i][j] << endl; 
            }
  
            // If the last character is different, consider all 
            // possibilities and find the minimum       
            else{
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert 
                                   dp[i-1][j],  // Remove 
                                   dp[i-1][j-1]); // Replace 
                // cout << i << " " << j << " " << dp[i][j] << endl; 
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
    //cin.tie(0);

    string s, t;
    cin >> s >> t;

    cout << editDist(s,t, s.size(), t.size()) << endl;
}    