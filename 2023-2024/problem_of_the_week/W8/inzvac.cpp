#include <iostream>
#define int long long
using namespace std;

int32_t main(){
    // inzvac
    int i = 0; int in = 0; int inz = 0; int inzv = 0; int inzva = 0; int inzvac = 0;
    int n; cin >> n;
    string s; cin >> s;
    for (int count = 0; count < n; count++)
    {
        if(s[count] == 'i') i++;
        if(s[count] == 'n'&& i > 0) in = (in + i)%1000000007;
        if(s[count] == 'z'&& in > 0) inz = (inz + in)%1000000007;
        if(s[count] == 'v'&& inz > 0) inzv = (inzv + inz)%1000000007 ;
        if(s[count] == 'a'&& inzv > 0) inzva = (inzva + inzv)%1000000007;
        if(s[count] == 'c'&& inzva > 0) inzvac = (inzvac + inzva)%1000000007;
    }
    cout <<( inzvac)%1000000007 <<endl;
    
}