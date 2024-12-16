#include <iostream>
#include <vector>
using namespace std;

int32_t main(){
    int n;cin>>n;
    n--;
    vector<int> parent(n+1);
    parent[1]=0;
    for(int i = 0; i < n-1; i++)
    {
        int a;cin>>a;
        parent[i+2]=a;
    }
    int q;int depth = 0;
    while(parent[q]!=1){
        q = parent[q];
        depth++;
    }
    cout<<depth<<endl;
}