#include <iostream>
#include <queue>
using namespace std;

int32_t main(){
    int n,m; cin>>n>>m;
    priority_queue<pair<int,int> > pq_l;
    priority_queue<pair<int,int> > pq_r;
    for (int edge = 0; edge < m; edge++)
    {
        int u,v; cin>>u>>v;
        if(v>u) pq_l.push(make_pair(u,v));
        else pq_r.push(make_pair(v,u));
    }

    while(!pq_l.empty() && !pq_r.empty()){
        if(pq_l.top()!=pq_r.top()){
            cout<<"No";
            return 0;
        }
        else{
            pq_l.pop();
            pq_r.pop();
        }
    }
    if(pq_l.empty() && pq_r.empty()) cout<<"Yes";
    else cout<<"No";

}