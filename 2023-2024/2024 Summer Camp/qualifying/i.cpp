#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int32_t main(){
    int n; cin>>n;
    if(n==1) return 1;
    if(n==0) return 0;

    vector<pair<int,int> >dishes(n,make_pair(0,0));
    for (int i = 0; i < n; i++) cin >> dishes[i].first >> dishes[i].second;
    sort(dishes.begin(),dishes.end());
    vector<int> seconds(n,0);
    for (int i = 0; i < n; i++) seconds[i] = dishes[i].second;
    vector<int> lis;
    for (int num : seconds) {
        auto it = upper_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) lis.push_back(num);  else  *it = num;
    }
        
    cout<<lis.size()<<endl;

    

}