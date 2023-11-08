#include <iostream>
#include <cmath>
using namespace std;
#define int long long
#define max_n 200002

//Defining some global variables
int arr[max_n]; int tree[4*max_n];


int query(int index,int tl,int tr,int a, int b){
    if(a>tr || b<tl) return 0;
    if(a<= tl && b>= tr){
        return 1;
    }
    int mid = tl + (tr-tl)/2;
    int t1 = query(2*index,tl,mid,a,b);
    int t2 = query(2*index+1,mid +1,tr,a,b);
    return t1+t2;
}


int32_t main(){

    int result;

    for(int i=0;i<10000;i++){
        int n=i;
    if(n==1 || n==2){
        result=1;
    }
    if(n==3){
        result=2;
    }
    
    double log_result = log2(n);
    bool is_integer=false;

    int log_int = log_result/1;
    if(log_result==log_int) is_integer=true;;


    if(is_integer){
        result=(log_int-1)*2;
        
    }
    else{
        result = ((log_int-1)*2)+1;
    }

    int result2;
            
            int max_number = 0;
        for (int k = 0; k < n; k++)
        { 
            for (int j = k; j < n; j++)
            {
                max_number = max(max_number,query(1,1,n,k,j));
            }
            
        }
    result2 = max_number;
    if(result==result2){cout<<"true for n="<<i<<endl; }
    else{cout<<"false for n="<<i<<endl;}
    }
return 0;
}