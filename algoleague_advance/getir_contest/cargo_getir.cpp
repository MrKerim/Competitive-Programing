#include <iostream>
#include <vector>
#define int long long
using namespace std;

int32_t main(){
    int n;
    vector<vector<pair<int,int> > > graph(n);
    for (int i = 0; i < n-1; i++)
    {
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back(make_pair(w,v));
        graph[v].push_back(make_pair(w,u));
    }

    int q; cin>>q;
    while (q--)
    {
        int type; cin>>type;
        if(type == 1){
            int a,b; cin>>a,b;
            
        }
        else{
            int a,b,k; cin>>a>>b>>k;

        }
    }
       
    return 0;
}
