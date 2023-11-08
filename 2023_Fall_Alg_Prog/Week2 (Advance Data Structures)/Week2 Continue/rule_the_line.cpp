#include <iostream>
#include <vector>
#include <algorithm>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define max_n 200005
using namespace std;
int tree[4*max_n]; int power[max_n];

int query(int index, int tl , int tr, int a, int b){
    if(a>tr || b<tl) return 0;
    if(a<=tl && tr<=b) return tree[index];
    int mid = tl + (tr - tl)/2;
    int t1 = query(2*index,tl,mid,a,b);
    int t2 = query(2*index+1,mid+1,tr,a,b);
    return max(t1,t2);
}
void update(int index, int tl, int tr, int a,int b, int value){
    if(a>tr || b<tl) return;
    if(a<=tl && tr<=b) {tree[index]+=value; return;}
    int mid = tl + (tr - tl)/2;
    update(2*index,tl,mid,a,b,value);
    update(2*index+1,mid+1,tr,a,b,value);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}

int32_t main(){
    Iamspeed
    
    int n;cin>>n;
    vector<pair<int,int> > elements(n);
    for (int i = 0; i < n; i++)
    {
        cin>>elements[i].first;
        elements[i].second = -i;
    }

    for (int i = 0; i < n; i++) { cin>>power[i]; }
    
    sort(elements.begin(),elements.end());
    for(auto elem: elements)
    {
        int max_pow = query(1,1,n,1,- elem.second) + power[-elem.second];
        update(1,1,n,1-elem.second,1-elem.second,max_pow);
    }
    cout<<tree[1]<<endl;
    

    return 0;
}