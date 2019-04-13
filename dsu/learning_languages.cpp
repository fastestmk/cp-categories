#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>

using namespace std;

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5;

int parent[110], rnk[110];
int n, m, k;
bool vis[110][110];

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

	for(int i = 0; i < n; ++i){
		cin >> k;
		for(int j = 0; j < k; ++j){
			int x;
			cin >> x;
			vis[i][x-1] = true;
		}
	}

	bool nonzero = false;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(vis[i][j])
				nonzero = true;
		}
	}

	if(!nonzero){
		cout << n << endl;
		return 0;
	}

	init();

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i < j){
				bool found = false;
				for(int k = 0; k < m; ++k){
					if(vis[i][k] && vis[j][k]){
						//cout << i << " " << k << " " << j << " " << k << endl; 
						found = true;
					}
				}
				if(found){
					connect(i,j);
					//cout << i  << " " << j << endl;
				}
			}
		}
	}

	//for(int i = 0; i < n; ++i){
	//	cout << i << " " << rnk[i] << endl;
	//}

	int comp = 0;
	for(int i = 0; i < n; ++i){
		if(root(i) == i) // checking parent only
			comp++;
	}
	cout << comp-1 << endl;
}