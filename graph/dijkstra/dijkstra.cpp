#include<iostream>
#include<vector>
#include<cmath> 
#include<set>
#include<algorithm>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5;

ll dis[200000];
vector<pair<ll, ll> > g[200000];
set<pair<ll, ll> > s;
ll parent[200000];
vector<ll> ans;

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    for(int i = 1; i <= n; ++i){
        dis[i] = 1e15;
    }

    dis[1] = 0;
    s.insert({0, 1});

    while(!s.empty()){
        //cout << s.begin()->first << " " << s.begin()->second << endl;
        int v = s.begin()->second;
        s.erase(s.begin());

        for(int i = 0; i < g[v].size(); ++i){
            ll to = g[v][i].first;
            ll len = g[v][i].second;
            if(dis[v]+len < dis[to]){
                s.erase({dis[to], to});
                dis[to] = dis[v]+len;   
                parent[to] = v;
                //cout << dis[to] << " " << to << endl;
                s.insert({dis[to], to});
            }
        }
    }

    //for(int i = 1; i <= n; ++i){
      // cout << i << " " << dis[i] << endl;
    //}

    if(dis[n] > 1e14)
        cout << -1 << endl;
    else{
        ans.push_back(n);
        while(n > 1){
            ans.push_back(parent[n]);
            n = parent[n];
        }
        reverse(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

}

// https://codeforces.com/contest/20/problem/C