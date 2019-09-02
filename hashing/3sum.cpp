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

bool threeSum(vector<int> vec, int sum){
	int n = vec.size();
	unordered_map<int, int> map;
	for(int i = 0; i < n; ++i){
		map[vec[i]] = i;
	}

	for(int i = 0; i < n-1; ++i){
		for(int j = i+1; j < n; ++j){
			int val = sum-(vec[i]+vec[j]);
			if(map.find(val) != map.end()){ // if triple found
				if(map[val] != i && map[val] != j){ // if triples don't overlap
					cout << val << " " << vec[i] << " " << vec[j] << endl;
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec{2, 7, 4, 0, 9, 5, 1, 3};
    int sum = 6;
    cout << (threeSum(vec, sum)?"triple exist" : "not") << endl;
}