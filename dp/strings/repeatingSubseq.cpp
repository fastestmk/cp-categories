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

bool isPalindrome(string temp){
	string str = temp;
	reverse(begin(str), end(str));
	if(str == temp)
		return true;
	return false;
}

int repeatedSubsequence(string str){
	int n = str.size();
	map<char, int> frq;
	for(int i = 0; i < n; ++i){
		if(++frq[str[i]] >= 3) // for cases like "aaa"
			return true;
	}

	string temp;
	for(auto c : str){
		if(frq[c] >= 2) 
			temp += c;
	}
	// cout << temp << endl;
	return (!isPalindrome(temp) ? 1 : 0);
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    cout << repeatedSubsequence(str) << endl;
}