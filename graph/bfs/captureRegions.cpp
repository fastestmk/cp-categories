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
const int MAX = 1e4+5;

int m, n;
vector<vector<int> > vis;

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};


void dfs(int x, int y, vector<vector<char> > &board){
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++i){
        int newx = x+X[i];
        int newy = y+Y[i];
        if( newx >= 0 && newx < m && newy >= 0 && newy < n && !vis[newx][newy] && board[newx][newy] == 'O')
            dfs(newx, newy, board);
    }
}

int capturePosition(vector<vector<char> > &board){
    m = board.size();
    n = board[0].size();

    vis.resize(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i){ // left edge
        if(board[i][0] == 'O' && !vis[i][0]){
            dfs(i, 0, board);
        }

        if(board[i][n-1] == 'O' && !vis[i][n-1]){ // right edge
            dfs(i, n-1, board);
        }
    }

    for(int i = 0; i < n; ++i){ // top edge
        if(board[0][i] == 'O' && !vis[0][i]){
            dfs(0, i, board);
        }

        if(board[m-1][i] == 'O' && !vis[m-1][i]){ // bottom edge
            dfs(m-1, i, board);
        }
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 'O' && !vis[i][j]){
                board[i][j] = 'X';
            }
        }
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    m = 4, n = 4;
    vector<vector<char> > board(m, vector<char>(n));
    board = {{'X', 'X', 'X', 'X'},
             {'X', 'O', 'O', 'X'},
             {'X', 'X', 'O', 'X'},
             {'X', 'O', 'X', 'X'}};

    capturePosition(board);         
}             