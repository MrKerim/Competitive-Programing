#include <iostream>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
    int n,m; cin>>n>>m;
    priority_queue<int> pq;
    while (n--){int input;cin>>input;pq.push(input);}
    while (m--)
    {
        int elem = pq.top()/2;
        pq.pop(); pq.push(elem);

    }
    int res=0;
    while(!pq.empty()){
        res+=pq.top();
        pq.pop();
    }
    cout<<res<<endl;
    
}