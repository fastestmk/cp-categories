// https://atcoder.jp/contests/dp/tasks/dp_g
#include<iostream>
#include<vector>

using namespace std;

#define ll long long

const int MAX = 1e5+7;

vector<int> graph[MAX];
bool vis[MAX];
int dp[MAX];

int dfs(int s){
    if(vis[s])
        return dp[s];
    vis[s] = true;
    for(int i = 0; i < graph[s].size(); ++i){
        int t = graph[s][i];
        dp[s] = max(dp[s], dfs(t)+1); 
    }

    return dp[s];
}

int main(){
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);


    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int ans = 0;
    for(int i = 1; i <= N; ++i){
        ans = max(ans, dfs(i));
        //cout << ans << endl;
    }
    cout << ans << endl;
}   

