// Largest power of b such that n! is divisble by b^x. e.g. 6!/3 = 2
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

int main(){
	int n, b;
	cin >> n >> b;

	int res = 0;

	while(n){
		n /= b;
		res += n;
	}	
	cout << res << endl;
}