#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<set>
#include<string>
#include<map>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

int n, sum;
char res[MAX];

void findNDigitSumUtil(int n, int sum, char *res, int index){
    if(index > n || sum < 0)
        return;

    if(index == n){
        if(sum == 0){
            //res[n] = ' ';
            cout << res << " ";
        }
        return;
    }

    for(int i = 0; i <= 9; ++i){
        res[index] = i + '0';
        findNDigitSumUtil(n, sum-i, res, index+1);
    }
}

void findNDigitSum(){
    for(int i = 1; i <= 9; ++i){
        res[0] = i + '0';
        findNDigitSumUtil(n, sum-i, res, 1);
    }
}
int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> sum;
    findNDigitSum();
    
    cout << endl;
}
// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/