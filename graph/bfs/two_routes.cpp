// http://codeforces.com/problemset/problem/601/A
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int INF = 1e9+7;

bool vis[405][405];
vector<int> g;
vector<int> dis(405, INF);


int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);


	int n, m;
	cin >> n >> m;

	while(m--){
		int u, v;
		cin >> u >> v;
		vis[u][v] = vis[v][u] = true; // railwaya route == 1
	}

	if(vis[1][n]){ // if there is railway route 1 to N 
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(i!=j){ 
					vis[i][j]= !vis[i][j]; // for railways 0, for roads 1
					// cout << i << " " << j << " " << vis[i][j] << endl;
				}
			}
		}
	}
	g.push_back(1);
	dis[1] = 0;

	for(int i = 0; i < g.size(); ++i){
		int t = g[i];
		for(int j = 1; j <= n; ++j){
			if(vis[t][j] && dis[j] == INF){
				//cout << t << " " << j << endl;
				dis[j] = dis[t]+1;
				g.push_back(j);
			}
		}
	}
	if(dis[n] == INF)
		cout << -1 << endl;
	else
		cout << dis[n] << endl;
}