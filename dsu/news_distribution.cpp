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
const int MAX = 500*1000+5;

int n, m;
int parent[MAX], rnk[MAX];

void init(){
    for(int i = 0; i < n; ++i){
        parent[i] = i;
        rnk[i] = 1;
    }
}

int root(int x){
    if(parent[x] != x)
        parent[x] = root(parent[x]);
    return parent[x];
}

void connect(int x, int y){
	int rx = root(x), ry = root(y);
	if(rx == ry)
		return;

	if(rnk[rx] > rnk[ry]){
		parent[ry] = rx;	
		rnk[rx] += rnk[ry];
	}

	if(rnk[rx] <= rnk[ry]){
		parent[rx] = ry;
		rnk[ry] += rnk[rx];
	}
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    init();

    for(int i = 0; i < m; ++i){
        int k;
        cin >> k;
        int s;
        for(int j = 0; j < k; ++j){
            int usr;
            cin >> usr;
            usr--;
            if(j == 0)
            	s = usr;
            else
            	connect(s, usr);
        }
    }

    for(int i = 0; i < n; ++i){
        cout << rnk[root(i)] << " ";
    }
    cout << endl;

}

// https://codeforces.com/problemset/problem/1167/C