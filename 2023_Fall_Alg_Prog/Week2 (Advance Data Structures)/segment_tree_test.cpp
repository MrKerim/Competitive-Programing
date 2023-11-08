#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define max_n 200002

//Defining some global variables
int arr[max_n]; int tree[4*max_n];

void build( int index, int l, int r ){
    if(l==r){ tree[ index ] = arr[l]; return;}

    int mid = l + (r-l)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[ index ] = max(tree[ 2*index ] , tree[ 2*index + 1 ]);
}

void update(int index, int tl, int tr, int a, int b, int value){
    // If the the target nodes we are searching are not in the update scope we will just return.
    if( a>tr || b<tl ) return;
    // If the target nodes we are searcghing are in the range of the update scope we will return the update!
    if( a<=tl && b>=tr){
        tree[index]+=value;
        return;
    }
    int mid = tl + (tr-tl)/2;
    update(2*index,tl,mid,a,b,value);
    update(2*index + 1, mid+1,tr,a,b,value);
    tree[index] = max (tree[index*2] , tree[index*2 + 1]);
}

int query(int index,int tl,int tr,int a, int b){
    if(a>tr || b<tl) return 0;
    if(a<= tl && b>= tr){
        return tree[index];
    }
    int mid = tl + (tr-tl)/2;
    int t1 = query(2*index,tl,mid,a,b);
    int t2 = query(2*index+1,mid +1,tr,a,b);
    return max(t1,t2);
}


int32_t main(){
    fastio
    int n,q; cin>>n>>q;
    
    //Input array initialization
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    
    //build
    build(1,1,n);
    
    for (int i = 0; i < q; i++)
    {
        int type; cin>>type;
        if(type==1){
            int k,u; cin>>k>>u;
            k+=1;
            //update()
            update(1,1,n,k,k,u);
            
            
        }
        else{
            int a,b; cin>>a>>b;
            a+=1; b+=1;
            //cout<<query()<<endl;
            cout<<query(1,1,n,a,b)<<endl;
        }
    }
    

}