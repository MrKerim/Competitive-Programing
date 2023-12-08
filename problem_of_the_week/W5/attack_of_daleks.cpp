#include <iostream>
#include <vector>
using namespace std;

int32_t main(){
    int n=4;
    vector<int> daleks(n);
    for (int i = 0; i < n; i++)
    {
        cin>>daleks[i];
    }

 cout<<(daleks[0] ^ daleks[1] ^ daleks[2] ^ daleks[3]  )<<endl;
        
        return 0;
    
}