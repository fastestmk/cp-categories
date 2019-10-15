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

vector<int> Solution::solve(int A, int B, int C, int D){
    vector<int> res;
    if(D==0)
        return res;
 
    int ia = 0, ib = 0, ic = 0;
    int nexta = A, nextb = B, nextc = C;
 
    for(int i=0;i<D;i++){
        res.push_back(min(nexta, min(nextb, nextc)));
 
        if(res[i] == nexta)
            nexta = res[ia++] * A;
        if(res[i] == nextb)
            nextb = res[ib++] * B;
        if(res[i] == nextc)
            nextc = res[ic++] * C;
    }
 
    return res;
}
int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> res = solve(2, 3, 5, 5);
    for(auto i : res)
        cout << i << endl;
    
}