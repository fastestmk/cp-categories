#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<set>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

int main(){
  //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i = 0; i < n; ++i){
        cin >> seq[i];
    }
    
    vector<int> d(n+1, INF); // d[] is for maintaining subsequence of longest length
    d[0] = -INF;

    for(int i = 0; i < n; ++i){
      int j = upper_bound(d.begin(), d.end(), seq[i]) - d.begin();
      //cout << i << " " << seq[i] << " " << j << " ";
      if(d[j-1] < seq[i] && seq[i] < d[j]){
        d[j] = seq[i];
        //cout << d[j] << endl;
      }
    }
    
    int ans = 0;
    for(int i = 0; i <= n; ++i){
      if(d[i] < INF) // d[] will always be sorted, so gives longest length
        ans = i;
    }
    cout << ans << endl;
}

// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html