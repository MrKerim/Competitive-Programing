#include <iostream>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define max_n 200004
using namespace std;
int arr[max_n]; pair<int,int> tree[4*max_n];

void build(int index,int l,int r){
if(l==r){ 
    // First max , second min
    tree[index] = make_pair(arr[l],arr[l]);
    return;
}
int mid = l + (r - l)/2;
build(2*index,l,mid);
build(2*index+1,mid+1,r);
pair<int,int> p1 = tree[2*index];
pair<int,int> p2 = tree[2*index+1];
tree[index] = make_pair( max(p1.first,p2.first),
min(p1.second,p2.second) );

}

pair<int,int> query(int index, int tl, int tr, int a, int b){
if(b<tl || tr<a) return make_pair( INT32_MIN, INT32_MAX );
if(a<=tl && tr <= b ) return tree[index];
int mid = tl + (tr - tl)/2;
pair<int,int> p1 = query(2*index,tl,mid,a,b);
pair<int,int> p2 = query(2*index+1,mid+1,tr,a,b);
return make_pair( max(p1.first,p2.first),
min(p1.second,p2.second) );
}

int32_t main(){
    int n; int k;
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    
    // Tree building here
    build(1,1,n);

    int low_bound = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = low_bound; j <= i; j++)
        {
            // Getting maximum and minimum values from the tree
            pair<int,int> max_min = query(1,1,n,j,i);
            // Stair Case Solution
            if (max_min.first-max_min.second <= k ) {
                low_bound = j;
                cout<<j-1<<" ";
                break;
            }
            
        }
        
        
    }
    cout<<endl;
    
return 0;
}