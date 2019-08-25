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
	int cnt = 1;
	for(int i = 0; i < n-1; ++i){
		if(vec[i] != vec[i+1]){
			cnt = 1; // changing frq
			vec[j++] = vec[i];
		}
		else{ // if two consecutive elements are same
			cnt++;
			if(cnt == 2){ // keeping doubles of element 
				vec[j++] = vec[i];
			}
			if(cnt >= 3){ // if frq of element >= 3
				continue;
			}
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

    vector<int> vec{1,1,1,2,2,3};
	cout << solve(vec) << endl;   
}