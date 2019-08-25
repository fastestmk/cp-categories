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

vector<int> longSeq(vector<int> vec, int m){
	vector<int> ans;
	int n = vec.size();
	int left = 0, leftInd = 0, window = 0, cnt = 0;
	for(int right = 0; right < n; ++right){
		// if current element is 0, increase count of zeros in the 	current window by 1
		if(vec[right] == 0)
			cnt++;

		// window becomes unstable if number of zeros in it becomes more than k
		while(cnt > m){
			// if we have found zero, decrement number of zeros in the current window by 1
			if(vec[left] == 0)
				cnt--;

			// remove elements from the window's left side till window becomes stable again
			left++;
			// cout << right << " " << left << endl;
		}

		// when we reach here, the window [left..right] contains at-most
		// k zeroes and we update max window size and leftmost index of the window
		if(right - left + 1 > window){
			window = right - left + 1;
			leftInd = left;
		}
	} 
	// cout << "longest length " << window << " from ind " << leftInd << " to " << leftInd+window-1 << endl;

	for(int i = leftInd; i <= leftInd+window-1; ++i){
		ans.push_back(i);
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

    int m;
    cin >> m;
    vector<int> vec{1, 1, 0, 1, 1, 0, 0, 1, 1, 1,};
    vector<int> res = longSeq(vec, m);
    for(auto i : res)
    	cout << i << " ";
    cout << endl;
}