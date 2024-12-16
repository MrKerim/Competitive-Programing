#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

int32_t main(){
    int n;cin>>n;
    vector<int> prefix(n+1,0);
    for (int i = 1; i <= n; i++){ cin>>prefix[i]; prefix[i] += prefix[i-1]; }
    map<int,int> mp;
    for(int x: prefix) mp[x]++;
    int ans = 0;
    for(auto x: mp) { ans+= (x.second*(x.second-1))/2; }
    cout<<ans;
}