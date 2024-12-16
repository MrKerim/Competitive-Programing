#include <iostream>
#include <cmath>
using namespace std;

int32_t main(){

    int n; cin>>n;
    if(n==1 || n==2){
        cout<<1<<endl;
        return 0;
    }
    if(n==3){
        cout<<2<<endl;
        return 0;
    }
    
    double log_result = log2(n);
    bool is_integer=false;

    int log_int = log_result/1;
    if(log_result==log_int) is_integer=true;;


    if(is_integer){
        cout<<(log_int-1)*2<<endl;
        
    }
    else{
        cout<<((log_int-1)*2)+1<<endl;
    }



return 0;
}