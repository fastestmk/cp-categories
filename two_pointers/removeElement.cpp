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

int solve(vector<int> &vec, int val){
	int n = vec.size();
	int j = 0;
	for(int i = 0; i < n; ++i){
		if(vec[i] == val){
			continue;
		}
		else{	
			vec[j++] = vec[i];
		}
	}

	// for(auto i : vec){
	// 	cout << i << " ";
	// }
	return j;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int val;
    cin >> val;
    vector<int> vec{4, 1, 1, 2, 1, 3};
    cout << solve(vec, val) << endl;
}