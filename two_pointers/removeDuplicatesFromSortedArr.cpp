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

int solve(vector<int> &vec){
	int n = vec.size();
	int j = 0;
	for(int i = 0; i < n-1; ++i){
		if(vec[i] != vec[i+1]){ // if not same
			vec[j++] = vec[i]; // new vec
		}
	}
	vec[j++] = vec[n-1]; // last element 
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

    vector<int> vec{1,2,2,3,4,4,4};
    cout << solve(vec) << endl;
}