#include <iostream>
#include <stack>
using namespace std;
int32_t main(){
    int n;cin>>n;
    stack<int> q;
    for (int i = 0; i < n; i++)
    {
        int input;cin>>input;
        if(q.size()==0) q.push(input);
        else if(q.top() == input) q.pop();
        else q.push(input);
    }
    if(q.size() ==0 ) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    

    return 0;
}