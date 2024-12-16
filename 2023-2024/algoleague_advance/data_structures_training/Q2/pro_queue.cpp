#include <iostream>
#include <queue>
using namespace std;
int32_t main(){
    int n;cin>>n;
    priority_queue<int> pq;
    while (n--)
    {
        int type;cin>>type;
        if(type==1){ int x;cin>>x; pq.push(x); }
        else{
            if(pq.empty()) cout<<-1<<endl;
            else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
    }
    
}