#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int MaxN = 2*100002;
int arr[MaxN]; double tree_sd[4*MaxN];
int tree_sum[4*MaxN];

int comb_sd(int n1,int n2,double s1,double s2,int a1,int a2){
    double x1 = a1/n1; double x2 = a2/n2;
    double x12 = (a1 + a2)/(n1 + n2);
    double d1 = x12 - x1; double d2 = x12 - x2;
    return (n1 * (d1 * d1 + s1) + n2 * (d2 * d2 + s2))/(n1 + n2);
}

double sd(int x,int y){
    double mean = (x + y)/2.0;
    return ((x - mean) * (x - mean) + (y - mean) * (y - mean))/2.0;
}

// Segment Tree for standard deviation
void build(int index, int l, int r ){
    if(l==r) return;
    if(l+1 == r){ tree_sd[index] = sd(arr[l],arr[r]); return; }
    int mid = l + (r-l)/2;
    build(index*2, l , mid);
    build(index*2+1,mid+1,r);
    double sd1 = tree_sd[index*2]; double sd2 = tree_sd[index*2+1];
    int a1 = tree_sum[index*2]; int a2 = tree_sum[index*2+1];
    tree_sd[index] = comb_sd(mid-l+1,r-mid,sd1,sd2,a1,a2);
}

void build_sum(int index, int l, int r ){

    if(l == r){ tree_sum[index] = arr[l]; return; }
    int mid = l + (r-l)/2;
    build_sum(index*2, l , mid);
    build_sum(index*2+1,mid+1,r);
    tree_sum[index] = tree_sum[index*2] + tree_sum[index*2+1];
}

double query(int index, int l, int r, int a, int b){

    if(r<a || l>b ){ return -1; }
    if(l >= a && r <= b) return tree_sd[index];
    int mid = l + (r-l)/2;
    double t1 = query(index*2,l,mid,a,b);
    double t2 = query(index*2 + 1,mid+1,r,a,b);
    if(t1 == -1) return t2; if(t2 == -1) return t1; 
    return comb_sd(mid-l+1,r-mid,t1,t2,tree_sum[index*2],tree_sum[index*2+1]);
}


int32_t main(){
        int n,q; cin >> n >> q;
        for(int i=0;i<n;i++) cin >> arr[i];
        
        build_sum(1,1,n);
        build(1,1,n);
        for (int i = 1; i < 50; i++)
        {
            cout<<"tree node i: "<<tree_sd[i]<<"\n";
        }
        
        while(q--){
            int a,b; cin >> a >> b;
            cout << query(1,1,n,a,b) << endl;
        }
    }