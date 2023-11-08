#include <iostream>
#include <vector>

using namespace std;




int main(){
    int n,q; cin>>n>>q;
    int pre[n+1];
    pre[0]=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>pre[i]; pre[i] += pre[i-1];
    }
    
    return 0;
}