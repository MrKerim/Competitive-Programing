#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    long long revenue=0;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;

        revenue+= inp * (n-i)*(i+1);
    }

    cout<<revenue<<endl;
    return 0;

    
}