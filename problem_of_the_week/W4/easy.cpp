#include <iostream>
#define int long long
using namespace std;

int32_t main(){
    int q;
    while(q--){
        int x,y;cin>>x>>y;
        if(x<y) swap(x,y);

        if(x-y==1 || x-y==0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}