#include <iostream>
#include <vector>
#include <map>

using namespace std;
int32_t main(){
    map<int,int> r;
    int n;cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int first = input[i];
            int second = input[j];
            r[first^second]++;
            if(r[first^second]>1) {cout<<"Yes\n"; return 0;}
            
        }
        
    }
    cout<<"No\n";
    
}