#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

int32_t main(){
    int n;cin>>n;
    map<char,int> conv;
    conv['n'] = 0; conv['e'] = -1; conv['p'] = 1;
    map<int,int> mp;
    vector<int> prefix(n+1,0);
    for (int i = 1; i <= n; i++) {char input;cin>>input;
    prefix[i]+=prefix[i-1]; prefix[i]+=conv[input];}
    for (int i = 0; i <= n; i++) {mp[prefix[i]]++;}
    int result = 0;
    for(auto x:mp) result+=((x.second)*(x.second-1))/2;
    cout<<result<<endl;
}