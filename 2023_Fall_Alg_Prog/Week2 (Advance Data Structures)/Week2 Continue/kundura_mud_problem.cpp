#include <iostream>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define max_n 200005
using namespace std;
pair<int,int> tree[4*max_n]; int arr[max_n]; int lazy[4*max_n];
// Tree.first -> sum of muds
// Tree.second -> minimum of the muds
void build(int index, int l, int r){
    if(l==r){
        tree[index] = make_pair(arr[l],arr[l]);
        return;
    }
    int mid = l + (r-l)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    pair<int,int> p1 = tree[2*index];
    pair<int,int> p2 = tree[2*index+1];
    tree[index] = make_pair( p1.first + p2.first , min(p1.second,p2.second) );
}

void push(int index, int l, int r){
    int value = lazy[index];
    // For some dunno however \|/ this expresion might be true.
    tree[index].first += (r-l+1)*value;
    tree[index].second += value;
    lazy[index] = 0;

    if(l!=r){
        lazy[2*index] += value;
        lazy[2*index+1] += value;
    }

}

pair<int,int> query(int index,int tl, int tr, int a, int b){
    push(index,tl,tr);
    if(a>tr || b<tl) return make_pair(0,INT32_MAX);
    if(b>=tr && a<=tl) return tree[index];
    int mid = tl + (tr -tl)/2;
    pair<int,int> p1 = query(2*index,tl,mid,a,b);
    pair<int,int> p2 = query(2*index+1,mid+1,tr,a,b);
    return make_pair( p1.first + p2.first , min(p1.second,p2.second) );
}

void range_update(int index,int tl, int tr, int a, int b, int value){
    push(index,tl,tr);
    if(a>tr || b<tl) return;
    if(b>=tr && a<= tl){
        lazy[index]+=value;
        push(index,tl,tr);
        return;
    }
    int mid = tl + (tr -tl)/2;
    range_update(2*index,tl,mid,a,b,value);
    range_update(2*index+1,mid+1,tr,a,b,value);
    pair<int,int> p1 = tree[2*index];
    pair<int,int> p2 = tree[2*index+1];
    tree[index] = make_pair( p1.first + p2.first , min(p1.second,p2.second) );
    return;

}


int32_t main(){
    Iamspeed
    int n,Q; cin>>n>>Q;
    for (int i = 1; i <= n; i++) { cin>>arr[i]; }

    build(1,1,n);
    
    for (int q = 0; q < Q; q++)
    {
        char type;cin>>type;
        if(type=='M'){
            int a,b; cin>>a>>b;
            pair<int,int> res_pair = query(1,1,n,a,b);
            cout<< res_pair.second<<endl;
        }
        else if(type=='S'){
            int a,b; cin>>a>>b;
            pair<int,int> res_pair = query(1,1,n,a,b);
            cout<< res_pair.first<<endl;
        }
        else{
            int a,b,k;
            cin>>a>>b>>k;
            range_update(1,1,n,a,b,k);
        }
    }
    
    

}