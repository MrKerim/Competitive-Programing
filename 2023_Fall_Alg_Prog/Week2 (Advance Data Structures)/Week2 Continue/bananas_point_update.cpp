#include <iostream>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define max_n 100005
using namespace std;
pair<int,int> tree[4*max_n]; int arr[max_n]; bool store_check[max_n];
// tree.first -> sum
// tree.second -> number of stores that open

void build(int index, int l , int r){
    if(l==r) tree[index] = make_pair(arr[l],1);
    else{
    int mid = l + (r-l)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    pair<int,int> p1 = tree[2*index];
    pair<int,int> p2 = tree[2*index+1];
    // pair ( sum , number of open stores )
    tree[index] = make_pair( p1.first+p2.first , p1.second+p2.second );
    }
}

pair<int,int> query(int index, int tl , int tr, int a , int b){
    if (a>tr || b<tl) return make_pair(0,0);
    if (a<=tl && tr<=b) return tree[index];
    int mid = tl + (tr - tl)/2;
    pair<int,int> p1 = query(2*index,tl,mid,a,b);
    pair<int,int> p2 = query(2*index +1,mid+1,tr,a,b);
    return make_pair( p1.first+p2.first , p1.second+p2.second );
    
}

void point_update(int index,int tl ,int tr ,int a, int b){
    if(a>tr || b<tl) return;
    if(a<=tl && tr<=b) {
        // In updates we check the status:
        // If the status is on we turn it to off then 
        // Delete that value
        // Alter the number of stores to 0 which was 1 previously

        if(store_check[tl]){
            tree[index] = make_pair(0,0);
            store_check[tl] = false;    
        }
        else{
            tree[index] = make_pair(arr[tl],1);
            store_check[tl] = true;
        }
        
        return;
    }
    int mid = tl + (tr - tl)/2;
    point_update(2*index,tl,mid,a,b);
    point_update(2*index+1,mid+1,tr,a,b);
    pair<int,int> p1 = tree[2*index];
    pair<int,int> p2 = tree[2*index+1];
    tree[index] = make_pair( p1.first+p2.first , p1.second+p2.second );
    return;
}

int32_t main(){
    Iamspeed
    int n;cin>>n;
    for (int i = 1; i <= n; i++){ cin>>arr[i]; store_check[i] = true; }
    build(1,1,n);
    int Q; cin>>Q;
    for (int q = 0; q < Q; q++)
    {
        
        int type;cin>>type;
        if(type==2){
            int a, b; cin>>a>>b;
            pair<int,int> res_pair = query(1,1,n,a,b);
            if(res_pair.second ==0 ) cout<<-1<<endl;
            else{
                cout<<res_pair.first/res_pair.second<<endl;
            }
        }
        else{ 
            // type == 1 update
            int u;cin>>u;
            point_update(1,1,n,u,u);
        }

    }
    
    return 0;
}