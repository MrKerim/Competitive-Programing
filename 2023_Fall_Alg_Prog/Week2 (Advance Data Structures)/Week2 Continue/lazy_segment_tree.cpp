#include <iostream>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define max_n 200001
using namespace std;
int tree[4*max_n]; int arr[2*max_n]; int lazy[4*max_n];

void push(int index, int l, int r){
    // Get value then reset the lazy
    int value = lazy[index];
    // Add the value to the tree
    tree[index]+=value;
    lazy[index] = 0;
    // Then we need to add the lazy value to the childs
    if(l!=r){
        lazy[2*index] += value;
        lazy[2*index+1] += value;
    }
}

int query(int index, int tl, int tr, int a, int b){
    push(index,tl,tr);
    if ( a>tr || b<tl ) return 0;
    if ( a<=tl && tr<=b ) return tree[index];
    // Crossection
    int mid = tl + (tr-tl)/2;
    int t1 = query(2*index,tl,mid,a,b);
    int t2 = query(2*index+1,mid+1,tr,a,b);
    return max(t1,t2);
}

void update(int index, int tl, int tr, int a, int b){
    push(index,tl,tr);
    if( a>tr || b<tl ) return;
    if( a<=tl && tr<=b ) { 
        lazy[index]+=1;
        push(index,tl,tr);
        return;
    } 
    // Crossection
    int mid = tl + (tr - tl)/2;
    update(2*index,tl,mid,a,b);
    update(2*index+1,mid+1,tr,a,b);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}

int32_t main(){
    Iamspeed
    int n,q; cin>>n>>q;

    for (int i = 0; i < q; i++)
    {
        int type; cin>>type;
        if(type==1){
            int k,u;cin>>k>>u;
            k+=1;u+=1;
            update(1,1,n,k,u);
        }
            
        else{
            int a,b; cin>>a>>b;
            a+=1;b+=1;
            cout<<query(1,1,n,a,b)<<endl;
        }
    }
    

}

