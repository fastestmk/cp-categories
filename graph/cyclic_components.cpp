#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<set>
#include<string>
#include<map>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 2e5+5;

vector<int> g[MAX];
int deg[MAX];
bool vis[MAX];

int dfs(int u){
	vis[u] = true;
	int res = (g[u].size() == 2);
	for(auto to : g[u]){
		if(!vis[to]){
			res &= dfs(to);
		}
	}
	return res; // returning 1 if g[u].size==2,  else 0 
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);

    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
    	if(!vis[i] && dfs(i)){
    		ans++; // calculating components
    	}
    }

    cout << ans << endl;
}

//https://codeforces.com/contest/977/problem/E