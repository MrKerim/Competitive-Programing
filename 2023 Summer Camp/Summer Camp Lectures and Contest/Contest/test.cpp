
#include <iostream>
using namespace std;

int main() {
int n;
cin>>n;

if(n==1 or n == 0){
    cout<<0<<"\n";
    return 0;
}

long long f_1 = 0;
long  long f_2 = 1;

for(int i=3;i<n+1;i++){
    long long temp = f_2;
    f_2 = (f_1 + f_2 )*(i-1);
    f_1 = temp;
};

cout<<f_2%(1000000000+7)<<"\n";

return 0;
}