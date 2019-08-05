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

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<vector<int> > matrix(m, vector<int>(n));
    for(int i = 0; i < m; ++i){
    	for(int j = 0; j < n; ++j){
    		cin >> matrix[i][j]; // matrix with cell -1 and 0, 0 for passage and 1 for blockage
    	}
    }

    if(matrix[0][0] == -1)
    	return 0;
    for(int i = 0; i < m; ++i){ // filling 1 in place of 0 in first coulmn 
    	if(matrix[i][0] == 0)
    		matrix[i][0] = 1;
    	else
    		break; // if encountered with -1 break it 
    }

    for(int i = 1; i < n; ++i){ // filling 1 in place of 0 in first row
    	if(matrix[0][i] == 0)
    		matrix[0][i] = 1;
    	else
    		break;
    }

    for(int i = 1; i < m; ++i){
    	for(int j = 1; j < n; ++j){
    		if(matrix[i][j] == -1)
    			continue;
    		if(matrix[i-1][j] > 0) // left cell 
    			matrix[i][j] += matrix[i-1][j];
    		if(matrix[i][j-1] > 0) // upper cell
    			matrix[i][j] += matrix[i][j-1];
    		// cout << i << " " << j << " " << matrix[i][j] << endl;
    	}
    }
    cout << ( (matrix[m-1][n-1]) > 0 ? matrix[m-1][n-1] : 0 ) << endl;
}

// https://www.geeksforgeeks.org/count-number-ways-reach-destination-maze/