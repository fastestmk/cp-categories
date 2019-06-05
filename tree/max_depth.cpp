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

vector<int> tree[MAX];
int vis[MAX];
int level[MAX];

void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < tree[u].size(); ++i){
        int v = tree[u][i];
        if(!vis[v]){
            level[v] = level[u]+1;
            dfs(v);
        }
    }
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    int ans = 0; 
    for(int i = 1; i <= n; ++i){
        ans = max(ans, level[i]);
    }   
    cout << ans << endl;
}