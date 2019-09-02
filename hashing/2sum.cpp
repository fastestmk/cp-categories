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
#include<unordered_map>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

vector<int> twoSum(vector<int> vec, int sum){
	vector<int> ans;
	int n = vec.size();
	unordered_map<int, int> m;
	for(int i = 0; i < n; ++i){
		if(m.find(sum-vec[i]) != m.end()){
			ans.push_back(m[sum-vec[i]]+1);
			ans.push_back(i+1); 
			return ans; 
		}
		m[vec[i]] = i;
	}
	return ans;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    vector<int> vec{4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    vector<int> res = twoSum(vec, -3);
    for(auto i : res)
    	cout << i << " ";
    cout << endl;
}