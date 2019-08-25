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

int solve(vector<int> &A, vector<int> &B, vector<int> &C){
	int diff = MAX;
	int i = 0, j = 0, k = 0;

	while(i < A.size() && j < B.size() && k < C.size()){
		int low = min(min(A[i], B[j]), C[k]);
		int high = max(max(A[i], B[j]), C[k]);

		diff = min(diff, high-low);

		// advance index of the array with minimum value
		if(A[i] == low)
			i++;
		else if(B[j] == low)
			j++;
		else
			k++;
	}

	return diff;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> A{3, 6, 8, 10, 15};
    vector<int> B{1, 5, 12};
    vector<int> C{4, 8, 15, 16};

    cout << solve(A, B, C) << endl;
}