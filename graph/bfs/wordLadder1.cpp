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

using namespace std;


bool isAdj(string a, string b){
    int n = a.length();
    int cnt = 0;
 
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])
            cnt++;
        if(cnt>1)
            return false;
    }
 
    return true;
}
 
int ladderLength(string start, string end, vector<string> &dictV){
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int n = dictV.size();
    bool vis[n];
    memset(vis,false,sizeof(vis));
 
    queue<pair<string,int> > q;
 
    q.push({start, 1});
 
    while(!q.empty()){
        string temp = q.front().first;
        int lev = q.front().second;
        q.pop();
 
        if(temp==end)
            return lev;
 
        if(isAdj(temp, end))
            return lev+1;
 
        for(int i=0;i<n;i++){
            if(vis[i]==false && isAdj(temp, dictV[i])){
                vis[i] = true;
                q.push({dictV[i],lev+1});
            }
        }
    }
 
    return 0;
}

int main(){
	vector<string> arr{"hit", "hot", "dot", "dog", "cog"};
	cout << ladderLength("hit", "cog", arr) << endl;
}