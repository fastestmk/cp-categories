// https://codeforces.com/contest/1114/problem/C
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

ll legendre(ll n, ll x){
	ll res = 0;

	while(n){
		n /= x;
		res += n;
	}

	return res;
}

vector<pair<ll, ll> > factor(ll x){
	vector<pair<ll, ll> > ans;
	for(ll i = 2; i*i <= x; ++i){
		if(x%i)
			continue;
		ll cnt = 0;
		while(x%i==0){
			x /= i;
			cnt++;
		}
		ans.push_back({i, cnt});
	}
	if(x > 1){
		ans.push_back({x, 1});
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

	ll a, b;
	cin >> a >> b;
	vector<pair<ll, ll> > vec = factor(b);

	ll ans = 2e18;
	for(ll i = 0; i < vec.size(); ++i){
		ll max_power = legendre(a, vec[i].first);
		ans = min(ans, max_power/vec[i].second);
	}
	cout << ans << endl;

}