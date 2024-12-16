#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

int32_t main(){
    int n,m; cin>>n>>m;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {int inp; cin>>inp; mp[inp]++;}
    vector<pair<int,int> > dividers;
    for(int i=1;i*i<=m;i++){if(i*(m/i)==m) dividers.push_back(make_pair(i,m/i));}
    int res = 0;
    if(m!=0)
    for(pair<int,int> p: dividers){
        if(p.first!=p.second) res += mp[p.first]*mp[p.second];
        else res += mp[p.first]*(mp[p.second]-1)/2;
    }
    else
    res += mp[0]*(mp[0]-1)/2 + mp[0]*(n-mp[0]); 
    cout<<res<<endl;
}