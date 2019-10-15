#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<unordered_map>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

int n;
vector<int> tree[MAX];
int dis[MAX];

pair<int, int> bfs(int s){
	queue<int> q;
	q.push(s);
	memset(dis, -1, sizeof(dis));
	dis[s] = 0;

	while(!q.empty()){
		int t = q.front();
		q.pop();

		for(auto to : tree[t]){
			if(dis[to] == -1){
				q.push(to);
				dis[to] = dis[t]+1;
			}
		}
	}

	int maxDis = 0;
	int node;

	for(int i = 1; i <= n; ++i){
		if(maxDis < dis[i]){
			maxDis = dis[i];
			node = i;
		}
	} 

	return make_pair(node, maxDis);
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);	

    cin >> n;
    for(int i = 1; i < n; ++i){
    	int a, b;
    	cin >> a >> b;
    	tree[a].push_back(b);
    	tree[b].push_back(a);
    }
    pair<int, int> dis1, dis2;
    dis1 = bfs(1);
    dis2 = bfs(dis1.first);
    cout << "longest dis is from " << dis1.first << " to " << dis2.first << " of length " << dis2.second << endl;  
}