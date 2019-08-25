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
#include<unordered_set>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

void solve(vector<int> &col){
	int n = col.size();
	int i = 0, j = 0, k = n-1; // i for 0, k for 2
	while(j <= k){
		if(col[j] == 0)
			swap(col[i++], col[j++]); 
		else if(col[j] == 2)
			swap(col[k--], col[j]); 
		else
			j++;
	}
	for(auto i : col)
		cout << i << " ";
	cout << endl;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> col{0,1,0,0,1,2,2};
    solve(col);
}