#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);
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
    fastio
    
        

            int n; cin>>n;
            int max_number = 0;
        for (int i = 0; i < n; i++)
        { 
            for (int j = i; j < n; j++)
            {
                max_number = max(max_number,query(1,1,n,i,j));
            }
            
        }
    cout<<max_number<<endl;
    
    return 0;

}