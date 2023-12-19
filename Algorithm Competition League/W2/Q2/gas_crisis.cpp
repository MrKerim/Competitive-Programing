#include <iostream>
#define int long long
using namespace std;

int func(int n){
    int left_most_bit = 0;
    int left_bit = 0;
    int counter = 0;
    while (n>1)
    {   counter++;
        n%2==1?left_bit=counter:left_bit;
        n/=2;
    }
    left_most_bit = ++counter;
    if (left_bit>0)
    {
        int a = left_most_bit - left_bit;
        int b = left_bit;
        return left_most_bit -1 + (left_most_bit-1)*(left_most_bit-2)/2 + left_bit;
    }
    else{
        return left_most_bit -1 + (left_most_bit-1)*(left_most_bit-2)/2 ;
    }
    
    
}
int32_t main(){
    int q;cin>>q;
    while(q--){
        int query;cin>>query;
        cout<<func(query)<<endl;
    }
}