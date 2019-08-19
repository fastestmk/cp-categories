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

vector<int> tree[MAX];
int level[MAX];
int vis[MAX];

int n, dis;

void dfs(int s){
	vis[s] = 1;
	for(auto to : tree[s]){
		if(!vis[to]){
			level[to] = level[s]+1; // increasing distance level by level
			if(level[to] == dis){
				cout << to << " "; // printing elements at distance D
			}
			dfs(to);
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

    cin >> n >> dis;

    for(int i = 1; i < n; ++i){
    	int a, b;
    	cin >> a >> b;
    	tree[a].push_back(b);
    	tree[b].push_back(a);
    }

    level[2] = 1; // taking root as 2
    dfs(2);
    cout << endl;
}