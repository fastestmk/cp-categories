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
#include<climits>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

int X[] = {0, 0, 1, 1, 1, -1, -1, -1};
int Y[] = {1, -1, 0, 1, -1, 0, 1, -1};


string validPath(int target1, int target2, int circles, int radius, vector<int> &circlePosX, vector<int> &circlePosY){
	int vis[target1+1][target2+1];
	memset(vis, 0, sizeof(vis));

	for(int i = 0; i <= target1; ++i){
		for(int j = 0; j <= target2; ++j){
			for(int k = 0; k < circles; ++k){
				if(sqrt(pow(circlePosX[k]-i, 2)+pow(circlePosY[k]-j, 2)) <= radius){
					vis[i][j] = 1;
				}
			}
		}
	}

	if(vis[0][0] ==1 || vis[target1][target2] == 1)
		return "NO";

	queue<pair<int, int> > q;
	q.push({0, 0});
	vis[0][0] = 1;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if(x == target1 && y == target2)
			return "YES";
		for(int i = 0; i < 8; ++i){
			int newx = x+X[i];
			int newy = y+Y[i];
			if(newx >= 0 && newx <= target1 && newy >= 0 && newy <= target2 && vis[newx][newy] == 0){
				vis[newx][newy] = 1;
				q.push({newx, newy});
			}
		}
	}
	return "NO";
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int target1, target2, circles, radius;
    cin >> target1 >> target2 >> circles >> radius;
    vector<int> circlePosX = {1, 3};
    vector<int> circlePosY = {3, 3};
    if(validPath(target1, target2, circles, radius, circlePosX, circlePosY) == "YES")
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;	
}