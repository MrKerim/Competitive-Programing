#include <iostream>
#include <queue>
#define int long long
using namespace std;

int32_t main(){
    int n;cin>>n;
    priority_queue<int> pq;
    while(n--){
        int x;cin>>x;
        int bin_pos = 0;
        while (x>0)
        {
            if(x%2) pq.push(bin_pos);
            x/=2; bin_pos++;
        }
    }
    int result = 0;
    int prev = -1;
    int slot = 3;
    while(!pq.empty()){
        int top_n = pq.top(); pq.pop();
        if(top_n != prev){
            slot--;
        prev = top_n;
        if(slot == 0){
            result++;
            slot = 3;
        }
        }
    }
    if(slot != 3) result++;
    cout<<result<<endl;
}