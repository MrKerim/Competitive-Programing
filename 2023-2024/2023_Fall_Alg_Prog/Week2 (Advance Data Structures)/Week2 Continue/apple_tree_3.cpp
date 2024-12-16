#include <iostream>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define max_n 100005
using namespace std;
pair<int,int> tree[4*max_n]; int arr[max_n];
// min,max
void build(int index,int l, int r){
    if(l==r) tree[index] = make_pair(arr[l],arr[l]);
    else{
    int mid = l + (r-l)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    pair<int,int> p1 =tree[2*index];
    pair<int,int> p2 = tree[2*index+1];
    tree[index] = make_pair(min(p1.first,p2.first),max(p1.second,p2.second));
    }
    // Every node holds the min value of the nodes inside it
}

int query(int index,int tl,int tr,int a,int b, int k){
    if(tr<a || tl > b) return 0;
    if(a <= tl && b>= tr){
        if(tree[index].first>= k) return (tr-tl+1);
        if(tree[index].second <k) return 0;
        if(tr==tl) return 0;
    }
        int mid = tl + (tr -tl)/2;
        int t1 = query(2*index,tl,mid,a,b,k);
        int t2 = query(2*index+1,mid+1,tr,a,b,k);
        return t1+t2;
    
}

int32_t main(){
    Iamspeed
    int n,q; cin>>n>>q;
    for (int i = 1; i <= n; i++) { cin>>arr[i]; }
    build(1,1,n);
    for (int qq = 0; qq < q; qq++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        cout<<query(1,1,n,a,b,k)<<endl;

    }
    
    return 0;
}