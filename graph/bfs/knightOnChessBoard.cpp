#include <bits/stdc++.h> 

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

struct cell{
	int x, y;
	int dis;
	cell() {}
	cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

bool isInside(int x, int y, int a, int b){
	if(x >= 1 && x <= a && y >= 1 && y <= b)
		return true;
	return false;
}

int minStepsToReachTarget(int a, int b, int source1, int source2, int target1, int target2){
	int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

	queue<cell> q;
	q.push(cell(source1, source2, 0));

	cell t; // obj
	int x, y;
	bool vis[a+1][b+1];

	memset(vis, false, sizeof(vis));

	vis[source1][source2] = true;

	while(!q.empty()){
		t = q.front();
		q.pop();
		if(t.x == target1 && t.y == target2)
			return t.dis;
		for(int i = 0; i < 8; i++){
			x = t.x + dx[i];
			y = t.y + dy[i];
			cout << x << " " << y << " " << t.dis << endl;
			if(isInside(x, y, a, b) && !vis[x][y]){
				vis[x][y] = true;
				q.push(cell(x, y, t.dis+1));
			}
		}	
	}
	return -1;
}


int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
   	cout << minStepsToReachTarget(10, 3, 3, 1, 10, 1) << endl;
}