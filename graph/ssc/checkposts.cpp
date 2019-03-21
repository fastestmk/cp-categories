//https://codeforces.com/problemset/problem/427/C
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

const int MAX = 2e5+5;
const int mod = 1e9+7;

vector<long> g[MAX], gr[MAX];
bool vis[MAX];
vector<long> order, comp, temp;
long cost[MAX];

void dfs1(int v){
    vis[v]= true;
    for(int i = 0; i < g[v].size(); ++i){
        long to = g[v][i];
        if(!vis[to])
            dfs1(to);
    }
    order.push_back(v);
}

void dfs2(int v){   
    vis[v] = true;
    for(int i = 0; i < gr[v].size(); ++i){
        long to = gr[v][i];
        if(!vis[to])
            dfs2(to);
    }
    comp.push_back(v);
}

int main(){
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> cost[i];
    }
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u); 
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i])
            dfs1(i);
    }

    for(int i = 1; i <= n; ++i){
        vis[i] = 0;
    }
    
    long long count = 0;
    long long mincost = 0;
    long long way = 1;

    for(int i = 1; i <= n; ++i){
        long v = order[n-i];
        
        if(vis[v]){
            continue;
        }
        dfs2(v); 
        count++; // counting connected components
        temp.clear();


        //for(auto it: comp)
            //cout << it << endl;

        
        for(int j = 0; j < comp.size(); ++j){
            temp.push_back(cost[comp[j]]);
            //cout << temp[j] <<" ";
        }
        //cout << endl;
        sort(temp.begin(), temp.end());

        comp.clear();
        //cout << temp[0] << endl;
        mincost += temp[0]; // minimum cost from one subset of graph

        long p = 0;
        while(p+1 < temp.size() && temp[p+1] == temp[0]){
            ++p;
        }
        way = way*(p+1)%mod; // no of ways

    }
    cout << mincost << " "  << way << endl;
}
