#include <iostream>
#define int long long
using namespace std;

const int MaxN = 2*100002;
int arr[MaxN]; int tree[4*MaxN];

void build(int index, int l, int r ){

    if(l == r){ tree[index] = arr[l]; return; }
    int mid = l + (r-l)/2;
    build(index*2, l , mid);
    build(index*2+1,mid+1,r);
    tree[index] = tree[index*2] + tree[index*2+1];
}

int query(int index, int l, int r, int a, int b){

    if(r<a || l>b ){ return 0; }
    if(l >= a && r <= b) return tree[index];
    int mid = l + (r-l)/2;
    int t1 = query(index*2,l,mid,a,b);
    int t2 = query(index*2 + 1,mid+1,r,a,b);
    return t1 + t2;
}

void update(int index,int l, int r, int a, int b,int value){
    if(r<a || l>b ) return;
    if(l >= a && r <= b) {tree[index] = value; return;}
    int mid = l + (r-l)/2;
    update(index*2,l,mid,a,b,value);
    update(index*2 + 1,mid+1,r,a,b,value);
    return;
}

int32_t main(){
     int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  build(1, 1, n);
  for (int i = 0; i < q; i++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int k, u;
      cin >> k >> u;
      update(1, 1, n, k, k, u);
    }
    if (type == 2)
    {
      int a, b;
      cin >> a >> b;
      cout << query(1, 1, n, a, b) << endl;
    }
  }
    return 0;

}