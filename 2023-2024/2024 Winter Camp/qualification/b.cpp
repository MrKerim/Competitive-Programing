#include <iostream>
#include <vector>
#define int long long
using namespace std;

int32_t main(){
    int N;cin>>N;
    vector<int> dp(N,0);
    vector<pair<int,int> > first_tri(3,make_pair(0,0));
    // initializing the first two triangls' powers
    for (int i = 0; i < 3; i++){int x,y;cin>>x>>y; if(i==0) dp[0]-= 2*(x+y); else dp[0]+= (x+y);
        first_tri[i].first=x;first_tri[i].second = y;}
    for (int i = 0; i < 3; i++){int x,y;cin>>x>>y; if(i==0) dp[1]-= 2*(x+y); else dp[1]+= (x+y); }

    int tri = 2;
    while(tri<N){
        // We have the power of the first two so we need compute the dp[tri] now
        // To do this we will calculate the points
        int p1 = first_tri[0].first + first_tri[0].second;
        int p2 = first_tri[1].first + first_tri[1].second + 2*dp[tri-1];
        int p3 = first_tri[2].first + first_tri[2].second + 2*dp[tri-2];
        dp[tri] = p2 + p3 - 2*p1;
        tri++;
    }

    cout<<dp[N-1]<<endl;
    
}